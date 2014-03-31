#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address{
    int id;
    int set;
    // create a char array size 512
    char name[MAX_DATA];
    char email[MAX_DATA];
};

// a struct that just contains an Array of Address Structs
struct Database
{
	// create array of type Address struct size 100
	// so each row is an address struct
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	// ? create a pointer to FILE struct - but why do I not need to use the struct key word
	FILE *file;
	// ? create pointer to database struct
	struct Database *db;
};

void die(const char *message)
{
	// if we fail to fread, malloc (see funtions below where die is used)
	// I think that errno will have been set to something other than zero.
	// from the man page:
	// The  routine perror() produces a message on the standard error output, describing the last 	  // error encountered during a call to a system or library function.
	if(errno) {
		perror(message);
	} else {
		// otherwise just print our own error message
		// though no idea how we could end up here.
		printf("ERROR: %s\n", message);
	}
	
	exit(1) // indicates unsuccessful terminiation (zero would be successful termination);
}

void Address_print(struct Address *addr)
{
	// print the contents of the address struct
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// doesn't return anything - just loads contents of file into DB struct (all the address rows)
void Database_load(struct Connection *conn)
{
	// connection is a pointer to a file and an array of rows.
	// the conn->db is the pointer to the struct with array of rows
	// so this reads from conn->file into array.
	// each element of data is
	int rc = fread(
		conn->db, // read into this
		sizeof(struct Database), // size of each element (we're only reading one element which is 512 address structs!)
		1, // (nmemb) number of elements to read
		conn->file); // read from this
		
	// fread returns the number of items read - in this case 1! 
	if(rc != 1) die("Failed to load database");
}

// returns a pointer to Connection struct
struct Connection *Database_open(const char *filename, char mode)
{
	// note const *filename - readonly pointer can be inspected but not written to.
	// char mode is just the mode that fopen will open in
	
	// give me pointer to some memory the size of Connection (FILE Pointer and pointer to sturct with array of Address)
	struct Connection *conn =  malloc(sizeof(struct Connection));
	if(!conn) die ("Memory error");
	
	// initialise the connections db pointer - 512 Address structs in size? (no its always more google it!)
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error");
	
	if(mode == 'c') {
		// create file (or truncate existing one to zero length)
		conn->file =  fopen(filename, "w");
	} else {
		// open for reading and writing
		conn->file = fopen(filename, "r+");
		if(conn->file) {
			// load the contents of the file into Addresses array
			Database_load(conn);
		}
	}
	
	if(!conn->file) die("Failed to open file");
	
	return conn;
}

void Database_close(struct Connection *conn)
{
	if(conn)
	{
		// flushes any bufferd data and close the file descriptor
		if(conn->file) fclose(conn->file);
		// frees db memory i.e. address rows memory
		if(conn->db) free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
		// set the file position indicator for the stream to the beginning of the file
		rewind(conn->file);
		
		// write the conn->db (the address rows) to the file
		int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
		if(rc != 1) die("Failed to write to database");
		
		// flush all buffer data to the file.
		rc = fflush(conn->file);
		if(rc == 1) die("Cannot flush the database");
}

void Database_create(struct Connection *conn)
{
	int i = 0;
	
	for(i = 0; i < MAX_ROWS; i++) {
		// see note on prototypes
		// create a new address and give it an id and set = 0, all other fields will be initialised to zero.
		struct Address addr = {.id = i, .set = 0};
		// just set the row to this - see his note on why you don't use memcopy in modern c
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set) die("Already set, delete it first");
	
	addr->set = 1;
	// bug
	char *res = strncpy(addr->name, name, MAX_DATA);
	// bug
	if(!res) die("Name copy failed");
	
	res = strncpy(addr->email, email, MAX_DATA);
	if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	
	if(addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set");
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = { .id = id, .set = 0 };
	conn->db->rows[id]  = addr;
}

void Database_list(struct Connection *conn)
{
	int  i = 0;
	struct Database *db = conn->db;
	
	for(i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
		
		if(cur->set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[]) {
	if(argc < 3) die("USAGE ex 17<dbfile <action> [action params]");
	
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;
	
	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS)die("There's not that many records");
	
	switch(action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc != 4) die("Need id to get");
			
			Database_get(conn, id);
			break;
		case 's':
			if(argc != 6) die("Need id, name and email to set");
			
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if(argc != 4) die("need id to delete");
			
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
	}
	 Database_close(conn);

    return 0;
}

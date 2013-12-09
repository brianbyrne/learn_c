#include<stdio.h>

void go_south_east(int *lat, int *lon) 
{
	*lat = *lat - 1;
	*lon = *lon + 1;
}

void printString(char *string)
{
	printf("%s\n", string);	
}

int main(int argc, char *argv[])
{
	int latitude = 32;
	int longitude = -64;
	go_south_east(&latitude, &longitude);
	printf("Now at [%i,%i]", latitude, longitude);
	
	printString("asdfsafsdf");
	
	
	/*char test_string[] = "hello";
	
	printf("Print full string %s \n", test_string);
	
	printf("Print second char %c \n", *(test_string+1));
	
	char *test_string2 = "bad";
	
	printf("test %c\n", *(test_string2 + 1));
	
	//char *array_strings[] = {"Brian", "Camille", "Joshua"};
	
	//char **the_array = array_strings;
	
	//printf("Print test %c", *the_array);
	
	//printf("Print second char %c \n", *((*array_strings)+1));
	*/
	
	/*
	int x = 2;
	int y = 3;
	
	int *xp;
	
	printf("x=%d\n", x);
	xp = &x; // point at address of x
	*xp = 10; // change the value of the thing xp points at - so x = 10
	printf("x=%d\n", x);
	
	y=*xp;
	printf("y=%d\n", y);
	
	char *t = "aabcd";
	//char *s = s;
	

	//printf("&t = %d\n",&t);
	//printf("&s = %p\n",&s);
	*/
	
	int x =4;
	int *address_of_x = &x;
	int value_stored = *address_of_x; 
	
	
	
	
	return 0;
	
}

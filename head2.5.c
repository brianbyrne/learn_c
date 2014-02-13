#include<stdio.h>
#include<string.h>
void print_reverse(char *s) 
{
	size_t len =  strlen(s);
	
	// brian it looks like you can just use char pointer in arithmatic
	char *current_char = s + len - 1;

	while(current_char >= s) {
		printf("%c", *current_char);
		current_char = current_char -1;	
	}
	printf("\n");
}


int main(int argc, char *args[])
{
	
	print_reverse("brian");


	char search_for[80];

	fgets(search_for, 80, stdin);

	char *tracks[] = {
		"I left my something or other",
		"some other stupid name,",
		"dancing with a dork"
	};

	int i = 0;
	for(i = 0; i < 3; i++) {
		printf("Track  %s",tracks[i]);
		printf(" for %s\n", search_for);
		if(strstr(tracks[i], search_for)) {
			printf("Found in %s\n", tracks[i]);
		}		
	}
}

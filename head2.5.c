#include<stdio.h>
#include<string.h>

int main(int argc, char *args[])
{
	char search_for[80];

	fgets(search_for, 80, stdin);

	printf("Searched For: %s", search_for);

	char tracks[][80] = {
		"I left my something or other",
		"some other stupid name,",
		"dancing with a dork"
	};

	int i = 0;
	for(i = 0; i < 3; i++) {
		if(strstr(tracks[i], search_for)) {
			printf("%s\n", tracks[i]);
		}		
	}
}

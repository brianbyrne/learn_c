#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *args[]) {
	char line[80];
	
	FILE *in;
	FILE *file1 = fopen("ufo.csv", "w");
	FILE *file2 = fopen("others.csv", "w");
	
	if(!(in = fopen("spookys.csv", "r"))) {
		fprintf(stderr, "Can't open the file\n");
		return 1;
	}
	
	while(fscanf(in, "%79[^\n]", line) == 1) {
		if(strstr(line, "UFO")) {
			fprintf(file1, "%s\n", line);
		}
		else if(strstr(line, "likes")) {
			fprintf(file2, "%s\n", line);
		}
	}
	
	fclose(file1);
	fclose(file2);
}

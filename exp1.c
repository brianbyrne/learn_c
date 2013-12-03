#include<stdio.h>

int main(int argc, char *argv[])
{
	char test_string[] = "hello";
	
	printf("Print full string %s \n", test_string);
	
	printf("Print second char %c \n", *(test_string+1));
	
	char *array_strings[] = {"Brian", "Camille", "Joshua"};
	
	char *the_array = array_strings;
	
	
	printf("Print second char %c \n", *((*array_strings)+1));
}

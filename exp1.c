#include<stdio.h>

int main(int argc, char *argv[])
{
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
	

	printf("&t = %d\n",&t);
	//printf("&s = %p\n",&s);
	
	
}

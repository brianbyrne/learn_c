#include<stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.3;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";
	char empty[] = "";
	
	printf("you are %d miles away.\n",distance);
	printf("you have %f levels of power.\n",power);
	printf("you have %f awesome super powers. \n",super_power);
	printf("i have initial %c.\n",initial);
	printf("i have a last name %s.\n",first_name);
	printf("i have fist name %s\n",last_name);
	printf("my whole name is %s %c %s\n",first_name, initial, last_name);
	printf("%s", empty);
	
	return 0;
}

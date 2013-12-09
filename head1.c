#include <stdio.h>

void fortune_cookie(char msg[]) 
{
	printf("size of message %i\n",sizeof(msg) );
	printf("Message reads %s\n",msg);
	printf("message is stored at %p\n", &msg);
}

void size_of_stuff()
{
	char s[] = "how big is it";
	char *p = s;
	printf("size of arry %i\n", sizeof(s));
	printf("size of pointer %i\n", p );
}

int main(int argc, char *argv[]) 
{
	char *quote = "cookies make you fat";
	fortune_cookie(quote);	
}


CFLAGS=-Wall -g

all:
	#cc -o ex1 ex1.c
	#cc -o ex3 ex3.c
	#cc -o ex4 ex4.c
	#cc -o ex5 ex5.c
	#cc -o ex6 ex6.c
	#cc -o ex7 ex7.c
	#cc -o exp_pointers exp_pointers.c
	cc -o head1 head1.c

clean:
	rm -f ex1
	rm -f ex3
	rm -f ex4
	rm -f ex5
	rm -f ex6
	rm -f ex7
	rm -f exp1
	rm -f exp_pointers
	rm -f head1
	rm -f *.*~
	rm -f *~


	

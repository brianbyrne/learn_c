#include<stdio.h>
#include<string.h>

float lat;
float longt;
char info[80];

int main(int argc, char *args[]) {
	
	while(scanf("%f,%f,%79[^\n]", &longt, &lat, info) == 3) {
		if((lat < 34.0) || (lat > 26.0)) {
			printf("%f,%f,%s", longt, lat, info);
		}
	}
	
	return 0;
}

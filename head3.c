#include<stdio.h>
#include<string.h>

int main(int argc, char *args[]){
	float longitude;
	float latitude;
	char info[80];
	
	int started = 0;
	
	puts("data[=");
	
	while(scanf("%f,%f,%79[^\n]", &longitude, &latitude, info)== 3) {
		if(started) {
			printf(",\n");
		}
		else {
			started = 1;
		}
		printf("{latitude: %f, longitude: %f, info: '%s'}",longitude, latitude, info);
		
	}
	puts("\n]");
	return 0;
}



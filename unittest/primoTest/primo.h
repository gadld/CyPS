#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int esPrimo(int num){
	for(int i=2;i<num;i++){
		if(num%i==0){
			return 0;;
		}
	}
	return 1;
}
int esPrimoCircular(char* num){
	int n=atoi(num);
        int max=(int)strlen(num)-1;

        for(int i=0;i<=max;i++){
                if(!esPrimo(n)){
			return 0;
                       // printf("no es primo");
                }
                n=(n%10)*(int)pow(10,max)+n/10;
        }
	return 1;
       // printf("si es primo");

}/*
int main(int argc, const char *argv[]){
	int n=atoi(argv[1]);
	int max=(int)strlen(argv[1])-1;
	
	for(int i=0;i<=max;i++){
		if(!esPrimo(n)){
			printf("no es primo");
		}
		n=(n%10)*(int)pow(10,max)+n/10;
	}
	
	printf("si es primo");
	return 0;
}*/

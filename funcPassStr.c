#include <stdio.h>

int add(int, int, char*);

int main(){
	printf("Sum is: %d\n", add(2,3,"Hi"));
	return 0;
}

int add(int a, int b, char* s){
	printf("Your string: %s\n",s);
	return a + b;
}


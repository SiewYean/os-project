#include <stdio.h>
#include <string.h>

int main(){
	char a[64];
	char b[] = "ball";
	
	int d;
	int e = 12;

	strcpy(a, b);
	d = e;

	printf("%s %d\n", a,d);
	return 0;
}

#include <stdio.h>

int main(){
	int a;
	scanf("%d", &a);

	float f;
	scanf("%f", &f);

	char s[64];
	scanf("%s", s);

	printf("You entered: %d, %f, %s\n", a,f,s);
	return 0;
}

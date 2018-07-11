#include <stdio.h>
#include <string.h>

struct Person{
	char name[64];
	int ic;
	struct Address{
		char street[64];
		int postcode;
	}address;
};

void setData(char* name, int ic, char* street, int postcode, struct Person*);

void printData(struct Person*);

int main(){
	struct Person a;
	struct Person b;

	strcpy(a.name, "Adam");
	a.ic = 223345;
	strcpy(a.address.street, "Jalan Inti");
	a.address.postcode = 11600;

	setData("Eve", 556678, "Jalan A", 11400, &b);

	printData(&a);
	printData(&b);

	return 0;
}

void setData(char* n, int ic, char* st, int pc, struct Person* p){
	strcpy(p -> name, n);
	p -> ic = ic;
	strcpy(p -> address.street,st);
	p -> address.postcode = pc;
}

void printData(struct Person* p){
	printf("Name: %s\n", p -> name);
	printf("IC: %d\n", p -> ic);
	printf("Street: %s\n", p ->address.street);
	printf("Postcode: %d\n\n", p ->address.postcode);
}

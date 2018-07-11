#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct data{
	int id;
	char name[64];
};

void* tafx(void *arg){
	//tafx = thread a's function
	struct data *mydata = arg;
	int myid = mydata->id;
	char myname[64];
	strcpy(myname, mydata->name);

	printf("I am child, my id: %d, name: %s\n",myid, myname);
	return NULL;
}

void* tbfx(void *arg){
	//tafx = thread a's function
	struct data *mydata = arg;
	int myid = mydata->id;
	printf("I am child, my id: %d\n",myid);
	return NULL;
}

int main (){
	pthread_t ta, tb; //'ta' = 'thread a', but its just a variable name
	struct data tadata, tbdata; //'tadata' = ta's data
	tadata.id = 12;
	tbdata.id = 79;
	strcpy(tadata.name, "Adam");
	strcpy(tbdata.name, "Eve");

	if(pthread_create(&ta,NULL,&tafx,&tadata)!=0){
		printf("error creating thread ta\n");
	}

	if(pthread_create(&tb,NULL,&tbfx,&tbdata)!=0){
		printf("error creating thread tb\n");
	}
	//after you run, you can create a child called 'ta'/'tb'
	//2nd parameter = things you wanna share with parent
	//3rd parameter = function for child to do -> use pass by reference
	//4th parameter = arguement to give the child to read to do its job
	//-> pass struct must use pass by reference

	pthread_join(ta,NULL);
	pthread_join(tb,NULL);
	
	return 0;
}

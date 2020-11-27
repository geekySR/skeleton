#include <stdio.h>
#include <stdlib.h>

#define RUNNING 0
#define DONE    1

int protothread() {
	static int i = 0;
	int stepStatus = 0;

	switch(i){
		
		case 0 : printf(" Thread 1 is execuitng \n");
		stepStatus++;
		printf("Stepstatus is--> %d", stepStatus);
		return RUNNING;
	
		case 1: printf("Thread 2 is execuitng \n");
		stepStatus++;
		printf("%d", stepStatus);
		return RUNNING;

		case 2: printf("Thread 3 is execuitng \n");
		stepStatus++;
		printf("%d", stepStatus);
		return RUNNING;

		case 3: 
		printf("Thread 4 is executing \n");
		stepStatus++;
		printf("%d", stepStatus);
		return RUNNING;

	}
	// printf("protothread!\n");
	//follow the pdf tutorial
	return DONE;
}

int main(int argc, char *argv[]) {

	int i = 0;
	int ret;

	do {
		i++;
		ret = protothread();

	} while (ret != DONE);

	printf("thread stopped after %d calls\n", i);

	return 0;
}

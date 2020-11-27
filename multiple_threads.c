#include <stdio.h>
#include <stdlib.h>

#define RUNNING 0
#define DONE    1


typedef struct thread {
	int (*run)();
	struct thread *next;
} thread_t;

thread_t *threads = NULL;

void threads_add_tail(thread_t *t) {
	if (!threads) {
		threads = t;
		t->next = NULL;
		return;
	}

	thread_t *current = threads;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = t;
	t->next = NULL;
}

int thread_available() {
	if (threads) {
		return 1;
	} else {
		return 0;
	}
}

thread_t* threads_pop_front() {
	thread_t* front = threads;
	threads = front->next;
	return front;
}

int protothread1() {
	int  p1_thread_id;
	switch(p1_thread_id){

case 0: printf("prothothread 1 is executing in step 1 \n");
//print step ID here

case 1: printf("Protothread 1 is executing in step 2 \n");
//print step ID here

case 2: printf("Protothread 1 is executing in step 3 \n");
//print step ID here

case 3: printf("Protothread 1 is executing in step  4 \n");
//print step ID here
}
	return DONE;
}

int protothread2() {
	int p2_thread_id;

	switch(p2_thread_id){

		case 0: printf("Protothread 2 is executing in step 1");
		//print thread id here (See homework pdf instructions for reference)

		case 1: printf("Protothread 2 is executing in step 2");
		//print thread id here
	}

	return DONE;
}

int main(int argc, char *argv[]) {

	// create two protothreads
	thread_t *t1 = (thread_t*)malloc(sizeof(thread_t));
	t1->run = &protothread1;
	thread_t *t2 = (thread_t*)malloc(sizeof(thread_t));
	t2->run = &protothread2;

	threads_add_tail(t1);
	threads_add_tail(t2);

	while (thread_available()) {

		// get first thread and exectue
		thread_t* t = threads_pop_front();
		int ret = t->run();
		// remove completed threads from pool
		if (ret != DONE) {
			threads_add_tail(t);
		}
	}

	return 0;
}

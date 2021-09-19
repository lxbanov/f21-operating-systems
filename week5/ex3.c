#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Thread 0 - consumer, prints *buffer value if it is not empty
// Thread 1 - producer, puts 4 random chars to buffer, if it is not full
// The buffer has the maximum size of 4

int asleep[2] = {1, 1}; // Asleep flags
pthread_t *threads[2] = {NULL, NULL};

void wakeup(size_t n) {
	asleep[n] = 0;
}

void go_sleep(size_t n) {
	asleep[n] = 1;
}

char *buffer;


void thread_tick(int t_id) {
	if (t_id == 0 && asleep[0] == 0) { // If consumer is awake
		if (strlen(buffer) == 0) { // If nothing to consume
			go_sleep(0); // Go to sleep
			printf("The buffer content is empty\n");
		} else { // Otherwise read and free the buffer
			printf("The buffer content is %s\n", buffer);
			free(buffer);
	       	}
		wakeup(1); // Wake the 1 process up

	
	} else if (t_id == 1 && asleep[1] == 0) { // If producer is awake
		if (strlen(buffer) == 4) { // If nowhere to put
			printf("The buffer content is full\n");
			go_sleep(1); // Go to sleep
		} else {  // Otherwise put random word in it
			buffer = (char *) calloc(0, sizeof(char) * 5);
			for (int i = 0; i < 4; ++i) {
				buffer[i] = (rand() % 26) + 'a';
			}
			printf("%s has been put to buffer\n", buffer);	

		}
		wakeup(0); // Wake the 0 procces up
		
	}
}

void* on_thread_create(void* _t_id) {
	int t_id = *((int*) _t_id);
	printf("Process %d created\n");
	wakeup(t_id);
	while (1)
		thread_tick(t_id);
	return 0;
}

int t_id[2];

int main() {
	for (int i = 0; i < 2; ++i) {
		t_id[i] = i;
		threads[i] = (pthread_t*) calloc(0, sizeof(pthread_t));
	}
	srand(time(NULL));
	buffer = (char*) malloc(0);

	pthread_create(threads[0], NULL, on_thread_create, &t_id[0]);
	pthread_create(threads[1], NULL, on_thread_create, &t_id[1]);
	pthread_join(*threads[0], NULL);
	pthread_join(*threads[1], NULL);	
}

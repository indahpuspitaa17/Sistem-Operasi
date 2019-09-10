#include <stdio.h>
#include <pthread.h>
#define N 17

void *hello(void *arg) {
	puts("hello");
	pthread_exit(NULL);
	}
	
/*
//1 Thread	
int main() {
	pthread_t t;
	pthread_create(&t, NULL, hello, NULL);
	pthread_join(t, NULL);
	return 0;
}


//2 thread
int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, hello, NULL);
	pthread_create(&t2, NULL, hello, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
*/


int main() {
	pthread_t t[N];
	for(int i = 0; i < N; i++)
		pthread_create(&t[i], NULL, hello, NULL);
	for(int i = 0; i < N; i++)
		pthread_join(t[i], NULL);
	return 0;
}

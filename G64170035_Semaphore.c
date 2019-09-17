#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define N 100000
#define T 4

int sum = 0;
sem_t S;

void *array_sum(void *arg)
{
    int *A = (int*)arg;         // cast void* --> int*
    int i;

    for (i = 0; i < N/T; i++) {
		sem_wait(&S);
        sum += A[i];
        sem_post(&S);
	}

    pthread_exit(NULL);
}

int main()
{
    pthread_t t[T];
    int A[N], i;
	
	sem_init (&S, 0, 1);
    for (i = 0; i < N; i++)
        A[i] = rand()%10;

    for (i = 0; i < T; i++)
        pthread_create(&t[i], NULL, array_sum, &A[i*N/T]);

    for (i = 0; i < T; i++)
        pthread_join(t[i], NULL);

    printf("%d\n", sum);    // 448706
    return 0;
}

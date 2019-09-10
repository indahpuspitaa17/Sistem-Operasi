#include <pthread.h>
#include <stdio.h>

#define N 16

int jumlah = 0;

void *jumlah_array(void *arg)
{
	int *val_p = (int *)arg;
	for(int i=0; i<4; i++)
	{
		jumlah += val_p[i];
	}
	pthread_exit(0);
}

int main() {
	
	pthread_t thread[4];
	int A[4][4] = {{51,67,7,77},{35,78,65,93},{68,34,64,95},{4,73,52,91}};
	
	for(int i=0; i<4; i++) {
		pthread_create(&thread[i], NULL, jumlah_array, A[i]);
	}
	
	for(int i=0; i<4; i++) {
		pthread_join(thread[i], NULL);
	}
	
	printf("%d\n", jumlah);
	
	return 0;
	
} 

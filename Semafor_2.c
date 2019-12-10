#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex; 

FILE *fp;
void *islem(void *veri)
{		

	sem_wait(&mutex); 

	printf("\n%s ->> Girdi",veri); 
	
	fp = fopen("dosya1.txt", "a");	
    fprintf(fp,"%s\n", veri);
	fclose(fp);
	
	printf("\nCikti <<- %s\n",veri); 
    sem_post(&mutex); 
	
}

int main(void) {
	sem_init(&mutex, 1, 1); 
    pthread_t th1, th2,th3,th4;

    pthread_create(&th1, NULL, islem, "Process 1");
	pthread_create(&th2, NULL, islem, "Process 2");
	pthread_create(&th3, NULL, islem, "Process 3");
	pthread_create(&th4, NULL, islem, "Process 4");
	sleep(2);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);
	sem_destroy(&mutex); 

    return 0;
}

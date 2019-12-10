#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mux =1;

void v(){
	//if(mux==0){
	
	mux+=1;
	//}
}

void p(){
	
	while(mux<=0){
		printf("\n+");
	}
	mux-=1;
}
FILE *fp;
void *islem(void *veri)
{		

	p();
	//FILE *fp;
	printf("%d p cikti ->>%s",mux,veri);
	fp = fopen("dosya1.txt", "a");	
    fprintf(fp,"%s\n", veri);
	fclose(fp);
	v();
	printf("%d v cikti ->>%s",mux,veri);
	printf("\n\n");

}

int main(void) {
    pthread_t th1, th2,th3,th4;

    pthread_create(&th1, NULL, islem, "-- PRC 1 --");
	pthread_create(&th2, NULL, islem, "-- PRC 2 --");
	pthread_create(&th3, NULL, islem, "-- PRC 3 --");
	pthread_create(&th4, NULL, islem, "-- PRC 4 --");
	
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);

    return 0;
}

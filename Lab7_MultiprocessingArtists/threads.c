// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread.h>
#include <time.h>

#define NTHREADS 64

int colors[64][64*3];
int counter = 1;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int save(){
	FILE *fp;
	fp = fopen("threads.ppm", "w+");
	fputs("P3\n", fp);
	fputs("64 64\n", fp);
	fputs("255\n", fp);
	int i;
	int j;
	for(i = 0; i < 64; i ++){
		for (j = 0; j < 64 * 3; j ++){
			fprintf(fp, "%d", colors[i][j]);
			fputs(" ", fp);
		}
		fputs("\n", fp);
	}
	fclose(fp);
	return 1;
}

void *thread(void *vargp){

    pthread_mutex_lock(&mutex1);
    printf("Artist %d is painting\n",counter);
    // randomly choose a color
	int ColorID = rand() % 255;
    int i = 0;
    for (; i < 64*3; i++){
        colors[counter][i] = ColorID;
    }
    counter += 1;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    pthread_t tids[NTHREADS];
    printf("Artist starts at: %d\n", counter);
    srand(time(NULL));
    // create and execute multiple threads
    for (int i = 0; i < NTHREADS; i ++){
        pthread_create(&tids[i], NULL, thread, NULL);
    }

    for (int i = 0; i < NTHREADS; i ++) {
        pthread_join(tids[i], NULL);
    }

    printf("parent is exiting(last artist out!)\n");
    save();	
    return 0;
}

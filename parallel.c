#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Trap(int n);

int main(int argc, char* argv[]) {
int thread_count;
thread_count = strtol(argv[1], NULL, 10);
# pragma omp parallel num_threads(thread_count)
//Trap(4);
loop();
 
 return 0;
}

void Trap(int n) {

  int my_rank = omp_get_thread_num();
  int thread_count = 2; 
   int inicio=0;
   int final=inicio+n/thread_count-1;
   n=n-n/thread_count;

   
# pragma omp parallel for num_threads(thread_count)
 for(int i=0; i<n; i++){

 }

  printf("Thread %d desde %d hasta %d \n", my_rank, inicio, final);

} 


void loop(){
	int* a;
	int n = 4;
	a[0]=0;
	for(int i = 1; i<n; i++){
		a[i]=a[i-1]+1;
	}

}
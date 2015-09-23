# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>


struct to_read{
  FILE *fp;
  long int offset;
  int start;
  int tam;
};

struct word{
  char *words;
  int count;
};
  
void word_freq(struct to_read *data){
  char words[100];
  char *buffer = malloc(data->tam);

  int i,c;
  int i=0;c=0;

  fseek(data->fp, data->offset, data->start);
  fread(buffer, data->tam, 1, data->fp);
 
  for(i=0;i<data->tam;i++){
      if(buffer[i]==32){
          word[c] = '\0';
          
        }
      else{
          word[c++] = buffer[i];
        }
    }

  free(buffer);
  pthread_exit(NULL);

  return;
}



int main(int argc, char **argv)
{
  int nthreads, ret_val, tid, tam;
  void *status;
  FILE *fp;
  pthread_t *threads;

  struct to_read data;

  fp = fopen("ejm.txt", "r");
  
  if (fp==NULL)
    {
      perror("ERROR");
      exit(1);
    }

  printf("# threads: ");
  scanf("%d",&nthreads);
  threads = malloc(nthreads*sizeof(pthread_t));

 
  tam = 13219/nthreads;

  for(tid = 0; tid < nthreads-1; tid++){
      data.fp=fp;
      data.offset = tam;
      data.start = tid*tam+1;
      ret_val = pthread_create(&threads[tid], NULL, &word_freq, &data);
      
      if(ret_val!= 0) {
        printf ("Create pthread error!\n");
        exit (1);
      }
      pthread_join(threads[tid],&status);
    }



  data.fp=fp;
  data.offset = tam + (13219 % nthreads);
  data.start = (nthreads-1)*tam+1;
  ret_val = pthread_create(&threads[nthreads-1], NULL, &word_freq, &data);
      
  if(ret_val!= 0) {
    printf ("Create pthread error!\n");
    exit (1);
  }

  pthread_join(threads[nthreads-1],&status);

  fclose(fp);
  free(threads);

  pthread_exit(NULL);
  return 0;  
}

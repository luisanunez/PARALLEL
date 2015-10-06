
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
 
#define TAM 4

int main(int argc, char **argv)
{
    int i;
    int vet[TAM];
    int procs, myRank;
    int tag=10;


    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&procs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myRank);

    if(myRank == 0){
    for(i=0; i<TAM;i++){vet[i]=i;}

          for(i=1; i<procs;i++){
       MPI_Send(&vet,TAM,MPI_INT,i,tag,MPI_COMM_WORLD);
        }
    }
    else{
    MPI_Recv(&vet,TAM,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
        printf("processor %d  RECIBE: ",myRank);
    for(i=0; i<procs;i++){
            printf("num %d \n",vet[i]);
    }
    }

    MPI_Finalize();
}
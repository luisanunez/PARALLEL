#define N 512

#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stddef.h>
#include "mpi.h"

int a[N][N], b[N][N], c[N][N];


void fill_matrix(int mat[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            mat[i][j] = 1;
}


void print_results(char *prompt, int a[N][N])
{
    int i, j;

    printf ("\n\n%s\n", prompt);
    for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                    printf(" %.2f", a[i][j]);
            }
            printf ("\n");
    }
    printf ("\n\n");
}



int main(int argc, char *argv[])
{
    int i, j, k, rank, size, tag = 99, blksz, sum = 0;
    fill_matrix(a);
    fill_matrix(b);


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Scatter(a, N*N/size, MPI_INT, a, N*N/size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, N*N, MPI_INT, 0, MPI_COMM_WORLD);


    if (rank != 0) {
        for (i=0;i<size; i++){
            if (rank == i){
                for(i = rank*(N/size); i < (rank*(N/size)+(N/size)); i++){
                    for (j = rank*(N/size); j < (rank*(N/size)+(N/size)); j++){
                        for (k = rank*N; k < rank*N+N; k++){
                            sum = sum + a[i][k] * b[k][j];
                         }
                        c[i][j] = sum;
                        sum = 0;
                    }
                }
            }
        }
    }

    MPI_Gather(c, N*N/size, MPI_INT, c, N*N/size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Finalize();
  
    print_results("C = ", c);
}


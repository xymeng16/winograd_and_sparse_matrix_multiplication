// sparse matrix
#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#define MAXSIZE 4096

//Triad
typedef struct{  
 int i,j;  
 int v;  
}SPNode;  
//Triad list  
typedef struct{  
 int mu,nu,tu;  
 SPNode data[SMAX];  
}SPMatrix;  
#endif
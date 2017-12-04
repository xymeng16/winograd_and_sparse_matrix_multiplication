// // sparse matrix
// #include "sparse_matrix.h"
// #include <stdio.h>

// void sparse_matmul(sparse_matrix *A, sparse_matrix *B, sparse_matrix *res)
// {
// 	int temp[B->col_size], num[B->row_size], rpot[B->row_size];
// 	if (A->col_size != B->row_size)
// 	{
// 		printf("A's column size must be equal to B's row size!\n");
// 		return ;
// 	}

// 	if(A->non_zero_size * B->non_zero_size == 0)
// 	{
// 		res->non_zero_size = 0;
// 		return ;
// 	}

// 	for (int i = 0; i < B->row_size; ++i)
// 	{
// 		num[i] = 0;
// 	}

// 	for (int i = 0; i < B->non_zero_size; ++i)
// 	{
// 		++num[B->data[i].row];
// 	}

// 	for(int i = 1; i < B->row_size; ++i)
// 	{

// 	}
// }

#include "sparse_matrix.h"
#include <stdio.h>

void MulSMatrix(SPMatrix *A,SPMatrix *B, SPMatrix *C){  
  int p,j,q,i,r,k,t;  

  int temp[B->nu+1];  
  int num[B->mu+1],rpot[B->mu+1];  


  if(A->nu!=B->mu) return NULL;  
  C->mu = A->mu;  
  C->nu = B->nu;  

  if(A->tu*B->tu==0){  
    C->tu = 0;  
    return C;  
  }  
  //Compute the number of non-zero elements for each row in B
  for(i = 1;i<=B->mu;i++)  
    num[i] = 0;  
  for(i = 0;i<B->tu;i++)  
    num[B->data[i].i]++;  
  rpot[1] = 0;  
  //Compute the position of the first non-zero element for each row in B
  for(i = 2;i<=B->mu;i++)  
    rpot[i] = rpot[i-1]+num[i-1];  
   r = 0;//Store current number of non-zero elements in C
   p = 0;//Indicate the current position of non-zero element in A 
 
   for(i = 1;i<=A->mu;i++){  
       //Initialize the accumulator of Cij 
        for(j = 1;j<=B->nu;j++)  
            temp[j] = 0;  
      while(i==A->data[p].i){  
        k = A->data[p].j;

        if(k<B->mu) t = rpot[k+1];  
        else t = B->tu;  

        for(q = rpot[k];q<t;q++){  
            j = B->data[q].j;  
            temp[j] += A->data[p].v*B->data[q].v;  
        }  
       p++;  
      }  

      for(j = 1;j<=B->nu;j++){  
        if(temp[j]!=0){  
            C->data[r] = {i,j,temp[j]};  
            r++;  
        }  
      }  
   }  
   C->tu = r;  
}  
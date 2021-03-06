
/* Merge sort in C */
#include<stdio.h>
#include<stdlib.h>

#define ARRAY_MAX 100000 /*1000*/ /*100*/ /*10*/



void print_array(int *a, int n) {
    if (n > 0) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

/* Function to Merge Arrays L and R into A. 
   leftCount = number of elements in L
   rightCount = number of elements in R.*/

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
    int i,j,k;

    /*i - to mark the index of left subarray (L)
     j - to mark the index of right sub-array (R)
     k - to mark the index of merged subarray (A)*/

 
    i = 0; j = 0; k =0;

    while(i<leftCount && j< rightCount) {
        if(L[i]  < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

/*Recursive function to sort an array of integers. */ 
void MergeSort(int *A,int n) {
    int mid,i, *L, *R;
    if(n < 2) return; /* base condition. If the array has less than two element, do nothing.*/  
    mid = n/2; /*find the mid-index*/

    
    L = (int*)malloc(mid*sizeof(int)); 
    R = (int*)malloc((n- mid)*sizeof(int)); 
	
    for(i = 0;i<mid;i++) L[i] = A[i]; 
    for(i = mid;i<n;i++) R[i-mid] = A[i]; 

    MergeSort(L,mid);  
    MergeSort(R,n-mid);  
    Merge(A,L,mid,R,n-mid);  
    free(L);
    free(R);
}

int main() {
    /* Code to test the MergeSort function. */
    int my_array[ARRAY_MAX];
    int count = 0;
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count]))
        {
            count++;
        }
    MergeSort(my_array, count);
    
    print_array(my_array, count);
    return EXIT_SUCCESS;	
  
}

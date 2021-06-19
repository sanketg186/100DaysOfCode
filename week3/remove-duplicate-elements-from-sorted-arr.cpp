//  Remove duplicate elements from sorted Array 
//  Given a sorted array A of size N, delete all the duplicates elements from A.


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function */
int remove_duplicate(int A[],int N)
{
    int i=0,j=0,count=0;
    for(i=0;i<N-1;i++){
        if(A[i]!=A[i+1])
        A[j++]=A[i];
    }
    A[j]=A[N-1];
return j+1;
}
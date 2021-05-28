 // Postorder traversal from given Inorder and Preorder traversals 

 // Given a preOrder and inOrder traversal of a binary tree your task is to print the postOrder traversal 
// of the tree .You are required to complete the function printPostOrder which prints the node of the tree in 
// post order fashion . You should not read any input from stdin/console. There are multiple test cases. 
// For each test case, this method will be called individually.

#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


/*prints the post order traversal of the 
tree */

int search(int in[],int x,int n){
    
    int i;
    for(i=0;i<n;i++){
        if(in[i]==x)
        return i;
    }
    return -1;
}

void printPostOrder(int in[], int pre[], int n)
{
//Your code here
    int roo_indx=0;
    roo_indx=search(in,pre[0],n);
    
    if(roo_indx!=0)
    printPostOrder(in,pre+1,roo_indx);
    
    if(roo_indx!=n-1)
    printPostOrder(in+roo_indx+1,pre+roo_indx+1,n-roo_indx-1);
    
    cout<<pre[0]<<" ";
 
}
 // Min distance between two given nodes of a Binary Tree 
 // Given a binary tree and two node values your task is to find the minimum distance between them.

 
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/
 Node* findlca(Node*root,int a,int b){
     
     if(root==NULL)
        return root;
     if(root->data==a||root->data==b)
       return root;
     Node*left = findlca(root->left,a,b);
     Node*right = findlca(root->right,a,b);
     if(left&&right)
        return root;
     if(left)
        return left;
     if(right)
        return right;
    
     return NULL;
       
     
     
 }

int l;
void height(Node*root,int val,int k){
    if(root==NULL)
        return;
    
    if(root->data==val){
        l = k;
        return;
    }
    
    height(root->left,val,k+1);
    height(root->right,val,k+1);
    
    return;
}   
   
int findDist(Node* root, int a, int b)
{
    Node* r1=findlca(root,a,b);
    height(root,a,0);
    int x=l;
    height(root,b,0);
    int y=l;
    height(root,r1->data,0);
    int z=l;
    int res=x+y - 2*z;
    
    return res;
    // Your code here 
}
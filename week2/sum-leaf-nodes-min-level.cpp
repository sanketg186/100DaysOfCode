 // Sum of Leaf Nodes at Min Level 
 // Given a Binary Tree of size N, your task is to complete the function minLeafSum(), that should return the sum of all the leaf nodes that are at minimum level of the given binary tree.

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int minLeafSum(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<minLeafSum(root)<<endl;
  }
  return 0;
}
// Contributed by: Harshit Sidhwa
// } Driver Code Ends


//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
int minlevelsum(Node*root,int curr_level,int minlevel){
    if(root==NULL)
    return 0;
    if(root->left==NULL&&root->right==NULL &&curr_level==minlevel)
    return root->data;
    if(root->left==NULL&&root->right==NULL &&curr_level!=minlevel)
    return 0;
    
    if(root!=NULL){
        return minlevelsum(root->left, curr_level+1,minlevel)+minlevelsum(root->right,curr_level+1,minlevel);
    }
    
}

int findlevel(Node*root){
    if(root==NULL)
    return 0;
    int r1 = findlevel(root->left);
    int r2 = findlevel(root->right);
    if(root->left&&root->right)
    return 1+min(r1,r2);
    if(root->left)
    return 1+r1;
    if(root->right)
    return 1+r2;
}
int minLeafSum(Node* root)
{
    int min_level = findlevel(root);
    // cout<<min_level<<" ";
    return minlevelsum(root,0,min_level);
    
	// Code here
}
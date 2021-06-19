// ZigZag Tree Traversal 
// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.


// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

// } Driver Code Ends


//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
    vector<int>res;
    Node*curr=root,*tmp=NULL;
    // pair<int,Node*>temp;
    // queue<pair<int,Node*>>que;
    stack<Node*>stk1,stk2;
    // que.push(make_pair(0,curr));
    stk1.push(curr);
    while(!stk1.empty()||!stk2.empty()){
        while(!stk1.empty()){
            tmp = stk1.top();
            stk1.pop();
            res.push_back(tmp->data);
            
            if(tmp->left)
            stk2.push(tmp->left);
            
            if(tmp->right)
            stk2.push(tmp->right);
            
            
        }
        
        while(!stk2.empty()){
            tmp = stk2.top();
            stk2.pop();
            res.push_back(tmp->data);
            
            
             if(tmp->right)
             stk1.push(tmp->right);
            
            if(tmp->left)
            stk1.push(tmp->left);
            
           
        }
        
    }
    return res;
	// Code here
}
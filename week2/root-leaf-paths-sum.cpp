 // Root to leaf paths sum
 // Given a binary tree of N nodes, where every node value is a number. Find the sum of all the numbers which are formed from root to leaf paths.

 #include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
long long treePathsSum(Node *root);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		
        cout<<treePathsSum(root);
   		cout<<endl;
  }
  return 0;
}
// } Driver Code Ends


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */


void recur_sum(Node*roo,int cur_sum,int*sum){
    
    if(roo==NULL)
    return;
    if(roo->left==NULL && roo->right==NULL){
        *sum = *sum + cur_sum*10 + roo->data;
    }
    if(roo->left){
        recur_sum(roo->left,cur_sum*10+roo->data,sum);
    }
    if(roo->right){
        recur_sum(roo->right,cur_sum*10+roo->data,sum);
    }
    return;
}
/*You are required to complete below method */
long long treePathsSum(Node *root)
{
    //Your code here
    int sum=0;
    recur_sum(root,0,&sum);
    return sum;
}

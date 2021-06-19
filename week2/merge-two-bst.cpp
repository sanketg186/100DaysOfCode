//  Merge two BST 's 
// Given two BSTs, return elements of both BSTs in sorted form.


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
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



 // } Driver Code Ends



/*
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
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> res;
        stack<Node*> stk1,stk2;
        Node*curr1,*curr2,*top1,*top2;
        curr1 = root1;
        curr2 = root2;
        while(curr1 || curr2 || !stk1.empty() || !stk2.empty()){
            
            if(curr1){
                stk1.push(curr1);
                curr1 = curr1->left;
            }
            if(curr2){
                stk2.push(curr2);
                curr2 = curr2->left;
            }
            
            if(curr1==NULL&&curr2==NULL){
                top1=NULL;
                top2=NULL;
                if(!stk1.empty())
                top1 = stk1.top();
                if(!stk2.empty())
                top2 = stk2.top();
                if(top1!=NULL &&top2!=NULL){
                    if(top1->data<top2->data){
                        res.push_back(top1->data);
                        stk1.pop();
                        curr1 = top1->right;
                    }
                    else{
                        res.push_back(top2->data);
                        stk2.pop();
                        curr2 = top2->right;
                    }
                }
                else{
                    if(top1!=NULL){
                        res.push_back(top1->data);
                        stk1.pop();
                        curr1 = top1->right;
                    }
                    if(top2!=NULL){
                        res.push_back(top2->data);
                        stk2.pop();
                        curr2 = top2->right;
                    }
                }
            }
                
            }
            
            return res;
        }
       //Your code here
};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends
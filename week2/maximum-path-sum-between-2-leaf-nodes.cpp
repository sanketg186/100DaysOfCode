//  Maximum Path Sum between 2 Leaf Nodes
//  Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another leaf node.

// NOTE: Here Leaf node is a node which is connected to exactly one different node.

#include <bits/stdc++.h>

using namespace std;

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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
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
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    int recur(Node* root,int *sum){
        int left_sum,right_sum;
        if(root==NULL)
        return 0;
        if(!root->left&&!root->right)
        return root->data;
        
        if(root->left&&root->right){
        left_sum = recur(root->left,sum);
        right_sum = recur(root->right,sum);
        *sum = max(*sum,root->data+left_sum+right_sum);
        
        return max(left_sum,right_sum)+root->data;
        }
        
        if(root->left){
        left_sum = recur(root->left,sum);;
        return left_sum+root->data;
        }
        if(root->right){
        right_sum = recur(root->right,sum);;
        return right_sum+root->data;
        }
        
        
        
    }
    int maxPathSum(Node* root)
    {
        int sum=INT_MIN;
        int res=0;
        int x = recur(root,&sum);
        if(sum==INT_MIN)
        return x;
        return sum;
        // code here
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends
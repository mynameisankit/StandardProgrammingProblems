// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

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



int main() {
    
    string s ,ch;
    s = "16 4 N 17 11 N 12 15 N 10 3 N 1 13 N 14 8 N 13 10 N 14 11 N 3 7 N 9 15";
    Node* root = buildTree(s);

    vector <int> res = bottomView(root);
    for (int i : res) cout << i << " ";
    cout << endl;

    return 0;
}


// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

void bv(Node *root, map<int, int>& hd_and_value, map<int, int>& hd_and_depth , int depth, int hd) {
    if(root == NULL) {
        return;
    }
    else {
        //Left Call
        bv(root->left, hd_and_value, hd_and_depth, depth + 1, hd - 1);
        
        bool flag = false;

        map<int, int>::iterator it1, it2;
        
        //Find Value if it already exists
        it1 = hd_and_value.find(hd);
        
        //If found then update
        if(it1 != hd_and_value.end()) {
            
            it2 = hd_and_depth.find(hd);

            ////Update with new Value and Depth
            if(depth >= it2->second) {
                it1->second = root->data;
                it2->second = depth;
            }

            flag = true;
        }
        
        //If the value doesn't exist then update it
        if(!flag) {
            hd_and_value.insert({hd, root->data});
            hd_and_depth.insert({hd, depth});
        }
        
        //Right Call
        bv(root->right, hd_and_value, hd_and_depth, depth + 1, hd + 1);
        
        return;
    }
}

// Method that returns the bottom view.
vector<int> bottomView(Node *root) {
   map<int, int> hd_and_value; 
   map<int, int> hd_and_depth; 
   
   bv(root, hd_and_value, hd_and_depth, 0, 0);
   
   vector<int> ans;
   for(map<int, int>::iterator it = hd_and_value.begin(); it != hd_and_value.end(); it++) {
       ans.push_back(it->second);
   }
   
   return ans;
}
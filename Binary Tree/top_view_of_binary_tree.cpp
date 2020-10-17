// { Driver Code Starts
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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

void tv(Node *root, map<int, int>& hd_and_value, map<int, int>& hd_and_depth , int depth, int hd) {
    if(root == NULL) {
        return;
    }
    else {
        //Left Call
        tv(root->left, hd_and_value, hd_and_depth, depth + 1, hd - 1);
        
        bool flag = false;

        map<int, int>::iterator it1, it2;
        
        //Find Value if it already exists
        it1 = hd_and_value.find(hd);
        
        //If found then update
        if(it1 != hd_and_value.end()) {
            
            it2 = hd_and_depth.find(hd);

            ////Update with new Value and Depth
            if(depth <= it2->second) {
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
        tv(root->right, hd_and_value, hd_and_depth, depth + 1, hd + 1);
        
        return;
    }
}

// Method that returns the bottom view.
void topView(struct Node *root) {
   map<int, int> hd_and_value; 
   map<int, int> hd_and_depth; 
   
   tv(root, hd_and_value, hd_and_depth, 0, 0);
   
   for(map<int, int>::iterator it = hd_and_value.begin(); it != hd_and_value.end(); it++) {
       cout << it->second << " ";
   }
   
   return;
}
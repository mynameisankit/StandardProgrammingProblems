// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

void flatten_helper(Node *root) {
    if(root == NULL || root->next == NULL) {
        return;
    }
    else {
        Node *temp_v = root;
        Node *temp1, *temp2, *new_root;

        //Find a position for the node (root->next) if it exists in the bottom linked list of root
        while(temp_v->bottom != NULL && root->next != NULL && (temp_v->bottom)->data < (root->next)->data) {
            temp_v = temp_v->bottom;
        }

        //Save the the address of the next node if it exists after the current positon in
        //the bottom linked list of the root
        temp1 = temp_v->bottom;

        temp_v->bottom = root->next;
        root->next = NULL;
        temp_v = temp_v->bottom;

        //Save the new start of the mutli-level list
        new_root = temp_v->bottom;

        //Find the correct positions for the elements stored in list of temp
        while (temp1 != NULL) {
            while(temp_v->bottom != NULL && (temp_v->bottom)->data < temp1->data) {
                temp_v = temp_v->bottom;
            }

            temp2 = temp_v->bottom;
            temp_v->bottom = temp1;
            temp1 = temp1->bottom;
            temp_v = temp_v->bottom;
            temp_v->bottom = temp2;
        }

        flatten_helper(new_root);

        return;
    }
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root) {

    Node* temp1 = root, *temp2 = root->next;
    
    flatten_helper(root);
    
    return root;
}
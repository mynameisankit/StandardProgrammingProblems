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

void bottomView_helper(Node *root, map<int, int>& hd_and_value, map<int, int>& hd_and_depth , int depth, int hd) {
    if(root == NULL) {
        return;
    }
    else {
        //Left Call
        bottomView_helper(root->left, hd_and_value, hd_and_depth, depth + 1, hd - 1);
        
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
        bottomView_helper(root->right, hd_and_value, hd_and_depth, depth + 1, hd + 1);
        
        return;
    }
}

// Method that returns the bottom view.
vector<int> bottomView(Node *root) {
   map<int, int> hd_and_value; 
   map<int, int> hd_and_depth; 
   
   bottomView_helper(root, hd_and_value, hd_and_depth, 0, 0);
   
   vector<int> ans;
   for(map<int, int>::iterator it = hd_and_value.begin(); it != hd_and_value.end(); it++) {
       ans.push_back(it->second);
   }
   
   return ans;
}

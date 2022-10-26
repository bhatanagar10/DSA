bool validate(TreeNode* root , pair<int,int>range){
        if(!root)
            return true;
        if( !(root->val > range.first && root->val < range.second) ){
            return false;
        }

        bool left = validate(root->left , {range.first , root->val});
        bool right = validate(root->right, {root->val , range.second});

        if(left && right){
            return true;
        }

        return false;
    }

    bool isValidBST(TreeNode* root) {
        pair<int,int>range(INT_MIN , INT_MAX);
        return validate(root , range );
    }
    
    void solve(TreeNode* node , vector<TreeNode*>& trees ,unordered_map<int,int>&mp , int index){
        if(!node)
            return;
        
        auto it = mp.find(node->val);
        if(it != mp.end()){
            if(index == it->second || trees[it->second] == NULL)
                return;
            node->left = trees[it->second]->left;
            node->right = trees[it->second]->right;
            trees[it->second] = NULL;
            
            solve(node->left , trees , mp ,index);       
            solve(node->right , trees , mp , index);
        }
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if(trees.size() == 1)
            return trees[0];
        
        unordered_map<int,int>mp;
        
        for(int i=0 ; i< trees.size() ; i++){
            mp[trees[i]->val] = i;
        }
        
        //merge
        for(int i=0 ; i < trees.size() ; i++){
            if(!trees[i]){
                continue;
            }
            if(trees[i]->left == NULL && trees[i]->right == NULL){
                continue;
            }
                
            solve(trees[i]->left , trees , mp , i);
            solve(trees[i]->right , trees , mp , i);
        }
        
        //--------------------------------------------------------------------------
        //check if all tree been used
        int count=0;TreeNode* result=NULL;
        for(int i =0 ; i < trees.size() ;i++){
            
            if(trees[i]){
                result = trees[i];
                count++;
            }    
            if(count == 2)
                return NULL;
        }
        if(!isValidBST(result))
            return NULL;
        
        return result;
    }
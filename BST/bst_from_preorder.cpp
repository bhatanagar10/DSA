   //without using 2 range
   TreeNode* solve(vector<int>&preorder , int r , int &index){
        if( index >= preorder.size() || preorder[index] > r ){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder , root->val , index);
        root->right = solve(preorder , r, index);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        TreeNode* root = solve(preorder , INT_MAX , index);
        return root;
    }


    // normal
    TreeNode* solve(vector<int>&preorder , int r1 , int r2 , int &index){
        if( index >= preorder.size() || (preorder[index] < r1 || preorder[index] > r2)){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder ,r1 ,  root->val , index);
        root->right = solve(preorder , root->val , r2, index);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        TreeNode* root = solve(preorder ,INT_MIN , INT_MAX , index);
        return root;
    }
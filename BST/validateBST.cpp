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

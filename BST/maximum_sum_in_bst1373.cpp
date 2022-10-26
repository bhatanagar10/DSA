pair<pair<bool,int>,pair<int,int>> solve(TreeNode* root , int &sum){
        if(!root){
            return {{true , 0}, {INT_MAX , INT_MIN}};
        }
        
        pair<pair<bool,int>,pair<int,int>> left = solve(root->left , sum);
        pair<pair<bool,int>,pair<int,int>> right = solve(root->right , sum);
        pair<pair<bool,int>,pair<int,int>> result;
        
        result.second.second = max(root->val , right.second.second);
        result.second.first = min(root->val , left.second.first);
        result.first.second = left.first.second + right.first.second + root->val;
        
        if( left.first.first && right.first.first && ( root->val > left.second.second && root->val < right.second.first) ){
        
            result.first.first = true;
            sum = max(sum , result.first.second );
        }
        else{
            result.first.first = false;
        }
        
        return result;
}
    
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        pair<pair<bool,int>,pair<int,int>> answer = solve(root , sum);
        return sum;
    }
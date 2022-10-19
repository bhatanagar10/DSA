// two sum
bool twoSum(TreeNode* root , int k ,unordered_set<int>&s ){
        if(!root){
            return false;
        }

        if(s.find(k-root->val) != s.end()){
            return true;
        }
        s.insert(root->val);
        bool left = false , right = false;
        if(root->left){
            left = solve(root->left , k , s);
        }
        if(left){
            return left;
        }
        if(root->right){
            right = solve(root->right , k , s);
        }
        if(right){
            return right;
        }
        else{
            return false;
        }
    }


bool twoSum(TreeNode* root , int k){

    unordered_set<int>s;
    BinaryTreeNode *current = root, *pre;

    while(current){

        if(current->left == NULL){
            if(s.find(target - current->val) != s.end()){
                return true;
            }
            s.insert(current->val);
            current = current->right;

        }
        else{
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if(pre->right == NULL){
                pre->right = current;
                current= current->left;
            }

            else{
                pre->right = NULL;
                if(s.find(target - current->val) != s.end()){
                    return true;
                }
                s.insert(current->val);
                current= current->right;
            }

        }
    }
    return false;
}
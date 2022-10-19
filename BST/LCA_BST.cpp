// recursive approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = NULL;
        TreeNode* right = NULL;

        if(p->val < root->val && q->val < root->val){
            left = lowestCommonAncestor(root->left , p , q);
        }
        else if(p->val > root->val && q->val > root->val){
            right = lowestCommonAncestor(root->right , p , q);
        }
        else{
            return root;
        }

        if(left && right){
            return root;
        }
        else if(left){
            return left;
        }
        else if(right){
            return right;
        }
        else{
            return NULL;
        }
    }

//iterative approach
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){
            if(p->val < root->val && q->val < root->val){
                root= root->left;
              }
              else if(p->val > root->val && q->val > root->val){
                root = root->right
              }
              else{
                return root;
              }

        }
    }
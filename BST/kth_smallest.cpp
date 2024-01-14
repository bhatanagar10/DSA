int kthSmallest(TreeNode* root, int k){
    int count=0;int small=-1;

    // set current to root
    TreeNode *current = root;

    //loop until current exists
    while(current){
        //  if current left is NULL, then print that node and set current to current right
        if(current->left == NULL){
          count++;
          if(count == k){
              small = current->val;
          }
            current = current->right;
        }

        // else find the predecessor of that node, predecessor is rightmost element is the left subtree
        else{

            TreeNode *pre = findPredecessor(current);

            // if predecessor right is NULL, then set predecessor right to current  and current to current left
            if(pre->right == NULL){
                pre->right = current;
                current= current->left;
            }

            // else means predecessor right is set to current then set it back to NULL , print the current element than current to current right
            else{
                pre->right = NULL;
                count++;
                if(count == k){
                    small = current->val;
                }
                current= current->right;
            }

        }
    }
    return small;
}

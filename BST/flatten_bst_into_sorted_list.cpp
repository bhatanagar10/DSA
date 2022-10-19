void store_inorder(TreeNode<int>* root , vector<TreeNode<int>*>&vec){
    if(!root)
       return;
    
    store_inorder(root->left , vec);
    vec.push_back(root);
    store_inorder(root->right , vec);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<TreeNode<int>*>vec;
    store_inorder(root , vec);
    
    int n = vec.size();
    
    for(int i=0 ; i < n-1 ; i++){
        vec[i]->left = NULL;
        vec[i]->right = vec[i+1];
    }
    
    vec[n-1]->left = vec[n-1]->right = NULL;
    root = vec[0];
    return root;
    
}

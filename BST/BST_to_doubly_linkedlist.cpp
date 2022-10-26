void convertToDLL(TreeNode<int> *root, TreeNode<int>*& head){
    if(root == NULL)
        return;
    
    convertToDLL(root->right, head);
    
    root->right = head;
    if(head)
        head->left = root;
    head = root;
    
    convertToDLL(root->left, head);
}

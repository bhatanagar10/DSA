pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
    {
    // Write your code here.
    int p =-1, s=-1;
    if(!root)
        return make_pair(p,s);
    BinaryTreeNode<int>* head = root;
    //first for predecessor and second for successor

    while(head){
        if(head->data == key){
            if(head->left){
                BinaryTreeNode<int>*T = head->left;
                while(T->right){
                    T= T->right;
                }
                p = T->data;
            }
            if(head->right){
                BinaryTreeNode<int>*T = head->right;
                while(T->left){
                    T = T->left;
                }
                s = T->data;
            }
            return make_pair(p,s);
        }
        else if(key < head->data){
            s = head->data;
            head = head->left;
        }
        else{
            p = head->data;
            head = head->right;
        }
    }
    return make_pair(p,s);
}

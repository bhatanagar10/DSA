//-----------------------------------------------------------------using DSW algorithm----------------------------------------

void left_rotation(TreeNode<int>* &root){
    if(!root->right)
        return;

    TreeNode<int>* temp = root->right;

        int t = root->data;
        root->data = temp->data;
        temp->data = t;

        root->right = temp->right;
        temp->right = temp->left;
        temp->left = root->left;
        root->left = temp;
}

void right_rotation(TreeNode<int>* &root){

    if(!root->left)
        return;

    TreeNode<int>* temp = root->left;

        //exchange data of temp and root
        int t = root->data;
        root->data = temp->data;
        temp->data = t;
        
        root->left = temp->left;
        temp->left = temp->right;
        temp->right = root->right;
        root->right = temp;

}

TreeNode<int>* convert_to_vine(TreeNode<int>* root ,int &nodeCount){

    TreeNode<int>* node = root;

    while(root){
        if(root->left){
            //right rotation
           right_rotation(root);
        }
        else{
            root = root->right;
            nodeCount++;
        }
    }
    return node;
}
TreeNode<int>* merge_two_linked_list(TreeNode<int>* &root1, TreeNode<int>* &root2){

    TreeNode<int>* head = NULL ,*current = NULL;

    while(root1 && root2){
        if(root1->data <= root2->data){
            if(!head){
                head = root1;
                current = root1;             
            }
            else{
                current->right = root1;
                current = current->right;
            }
            root1 = root1->right;
        }
        else{
            if(!head){
                head = root2;
                current = root2;                
            }
            else{
                current->right = root2;
                current= current->right;
            }
            root2 = root2->right;
        }
    }
    if(root1){
        current->right = root1;
    }
    else if(root2){
        current->right = root2;
    }

    return head;
}

void createTree(TreeNode<int>* &root ,int nodeCount){

    //get perfect balance count
    int perfectBalanceCount =0 ,i=1;
    while(perfectBalanceCount < nodeCount){
        perfectBalanceCount = pow(2 ,++i)-1;
    }
    perfectBalanceCount = pow(2 , i-1)-1;
    int extraNodes = nodeCount - perfectBalanceCount;
    TreeNode<int>* current = root;
    // left rotations on odd nodes for extra nodes
    for(i =0 ; i< extraNodes ; i++ ){
        left_rotation(current);
        current=current->right;
    }

    // left rotations for perfect count
    int iterations = perfectBalanceCount;
    while(iterations){
        iterations/=2;
        current = root;
        for( i = 0 ; i < iterations ; i++){
            left_rotation(current);
            current=current->right; 
        }
    }
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    int count1 = 0 , count2 =0;
    TreeNode<int>* root3 = convert_to_vine(root1 , count1);
    TreeNode<int>* root4 = convert_to_vine(root2 , count2);

    TreeNode<int>* root = merge_two_linked_list(root3 , root4);
    createTree(root ,count1+count2);
    return root;
}



























// -----------------------------------------------------------------------------------------------------------------------

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

TreeNode<int>* merge(TreeNode<int>* head1, TreeNode<int>* head2){
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    
    while(head1 && head2){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
           if(head == NULL){
               head = head2;
               tail = head2;
               head2 = head2->right;
           }
           else{
               tail->right = head2;
               head2->left = tail;
               tail = head2;
               head2 = head2->right;
           } 
        }
    }
    
    while(head1){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right; 
    }
        
    while(head2){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    
    return head;
}

int countNodes(TreeNode<int> *head){
    int n = 0;
    TreeNode<int> *temp = head;
    while(temp){
        n++;
        temp = temp->right;
    }
    
    return n;
}

TreeNode<int>* convertDLLtoBST(TreeNode<int>*& head, int n){
    if(n <= 0 || head == NULL)
        return NULL;
    
    TreeNode<int> *leftTree = convertDLLtoBST(head, n/2);
    
    TreeNode<int>* root = head;
    root->left = leftTree;
    head = head->right;
    
    root->right = convertDLLtoBST(head, n-n/2-1);
    
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    TreeNode<int> *head1 = NULL, *head2 = NULL;
    convertToDLL(root1, head1);
    convertToDLL(root2, head2);
    
    TreeNode<int> *head = merge(head1, head2);
    
    int n = countNodes(head);
    
    TreeNode<int> *ans = convertDLLtoBST(head, n);
    
    return ans;
}
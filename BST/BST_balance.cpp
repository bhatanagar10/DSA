//day stout warren(DSW) algorithm
void left_rotation(TreeNode* &root){
    if(!root->right)
        return;

    TreeNode* temp = root->right;

        int t = root->val;
        root->val = temp->val;
        temp->val = t;

        root->right = temp->right;
        temp->right = temp->left;
        temp->left = root->left;
        root->left = temp;
}

void right_rotation(TreeNode* &root){

    if(!root->left)
        return;

    TreeNode* temp = root->left;

        //exchange val of temp and root
        int t = root->val;
        root->val = temp->val;
        temp->val = t;
        
        root->left = temp->left;
        temp->left = temp->right;
        temp->right = root->right;
        root->right = temp;

}

TreeNode* convert_to_vine(TreeNode* root , int &nodeCount){

    TreeNode* node = root;

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


void BST_balancing(TreeNode* root){

    int nodeCount = 0;
    TreeNode* node = convert_to_vine(root , nodeCount);

    //get perfect balance count
    int perfectBalanceCount =0 , i=1;
    while(perfectBalanceCount < nodeCount){
        perfectBalanceCount = pow(2,++i)-1;
    }
    perfectBalanceCount = pow(2,i-1)-1;

    int extraNodes = nodeCount - perfectBalanceCount;
    TreeNode* current = node;
    // left rotations on odd nodes for extra nodes
    for(i =0 ; i< extraNodes ; i++ ){
        left_rotation(current);
        current=current->right;
    }

    // left rotations for perfect count
    int iterations = perfectBalanceCount;
    while(iterations){
        iterations/=2;
        current = node;
        for( i = 0 ; i < iterations ; i++){
            left_rotation(current);
            current=current->right; 
        }
    }
    level_order_traversal(node);
}


//normal method
void store_inorder(TreeNode* root , vector<int>&vec){
    if(!root)
       return;
    
    store_inorder(root->left , vec);
    vec.push_back(root->val);
    store_inorder(root->right , vec);
}

TreeNode* solve(int l , int h , vector<int>vec){
    
    if(l > h){
        return NULL;
    }
    
    int mid = (l + h) / 2;
    TreeNode* root = new TreeNode(vec[mid]);
    
    root->left = solve( l , mid-1 , vec);
    root->right = solve( mid+1 , h , vec);   
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    // Write your code here.
    vector<int>vec;
    store_inorder(root , vec);
    root = solve( 0 , vec.size()-1 , vec);
    return root;
}
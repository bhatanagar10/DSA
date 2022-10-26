#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

pair<pair<bool,int>,pair<int,int>> solve(TreeNode<int>* root , int &maxi){
    if(!root){
        return {{true , 0}, {INT_MAX , INT_MIN}};
    }
    
    pair<pair<bool,int>,pair<int,int>> left = solve(root->left , maxi);
    pair<pair<bool,int>,pair<int,int>> right = solve(root->right , maxi);
    pair<pair<bool,int>,pair<int,int>> result;
    
        result.second.second = max(root->data , right.second.second);
        result.second.first = min(root->data , left.second.first);
        result.first.second = left.first.second + right.first.second + 1;
    if( left.first.first && right.first.first &&                                                                                                         ( root->data > left.second.second && root->data < right.second.first) ){
        
        result.first.first = true;
        maxi = max(maxi , result.first.second);
        
    }
    else{
        result.first.first = false;
    }
    
    return result;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxi = 0;
    pair<pair<bool,int>,pair<int,int>> answer = solve(root , maxi);
    return maxi;
}

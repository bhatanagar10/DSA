#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <typeinfo>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void display_binary_tree(TreeNode *Node){

      if(Node == NULL){
        return;
      }

      display_binary_tree(Node->left);
      cout<<Node->val<<" ";
      display_binary_tree(Node->right);
    }

class Tree {
public:
    int index;
    unordered_map<int,int>m;
    
    TreeNode *solve(vector<int>postOrder , int start , int end ){

    if(start > end || index < 0 )
        return NULL;
    
    //find the root element annd create a new node
    int root = postOrder[index--];
    TreeNode *node = new TreeNode(root);

    //find root in preorder 
    int position= m[root];

    node->right = solve(postOrder ,  position+1 , end );
    node->left = solve(postOrder , start , position-1 );
    
    
    return node;

}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    
    int start =0,end = postorder.size()-1;
    index = postorder.size()-1;
    
    for(int i = 0; i < inorder.size(); i++){
        m[inorder[i]] = i;
    }
    return solve( postorder, start , end);

    }
};

int code(){
    //code here 
    Tree t;
    vector<int> postorder ={9,15,7,20,3};
    vector<int> inorder ={9,3,15,20,7};
    TreeNode *root = t.buildTree(postorder , inorder);
    display_binary_tree(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
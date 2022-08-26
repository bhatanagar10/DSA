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

int findPosition(vector<int>inOrder ,int root){
    vector<int>::iterator it = find (inOrder.begin(), inOrder.end(), root);
    int position = distance(inOrder.begin(), it);
    return position;
}

int index = 0;
unordered_map<int,int>m;
    
    TreeNode *solve(vector<int>preOrder , int start , int end ){

    if(start > end || index >= preOrder.size())
        return NULL;
    
    //find the root element annd create a new node
    int root = preOrder[index++];
    TreeNode *node = new TreeNode(root);

    //find root in preorder 
    int position= m[root];

    
    node->left = solve(preOrder , start , position-1 );
    node->right = solve(preOrder ,  position+1 , end );
    
    return node;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    int start =0,end = preorder.size()-1;
    
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]] = i;
    }
    return solve( preorder, start , end);

}

int code(){
    //code here 
    vector<int> preorder ={1,2,3};
    vector<int> inorder ={2,3,1};
    TreeNode *root= buildTree(preorder , inorder);
    display_binary_tree(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
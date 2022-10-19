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

void flatten(TreeNode* root){
    TreeNode *current = root,*pre=NULL;
  
    while(current){
        TreeNode *temp = current;
        if(current->left){
            pre = current->left;
            while(pre->right){
                pre = pre->right;
            }
            pre->right = current->right;
            current->right= current->left;
            current->left= NULL;
        }
        current= current->right;
    }

}
int code(){
    //code here  
    TreeNode *root= new TreeNode(1);
    root->left= new TreeNode(2);
    root->left->left= new TreeNode(4); 
    root->left->right= new TreeNode(5);

    root->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->left->right=new TreeNode(8);
    root->right->left->left=new TreeNode(10);
    root->right->right= new TreeNode(7);
    root->right->right->right= new TreeNode(9); 

    flattenBinaryTree(root);
    display_binary_tree(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
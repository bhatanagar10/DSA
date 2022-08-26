/*
Morris Traversal:- 
first set current to root;


*/
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

TreeNode *findPredecessor(TreeNode *node){
    TreeNode *t= node;
    node= node->left;
    while(node->right != NULL && node->right !=  t){
        node = node->right;
    }
    return node;
}

void morris_traversal(TreeNode *node){

    // set current to root
    TreeNode *current = node;

    //loop until current exists
    while(current){

        //  if current left is NULL, then print that node and set current to current right
        if(current->left == NULL){
            cout<<current->val<<" ";
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
                cout<<current->val<<" ";
                current= current->right;
            }

        }
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
    display_binary_tree(root);cout<<endl;
    morris_traversal(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
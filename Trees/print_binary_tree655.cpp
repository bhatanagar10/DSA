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

void display_binary_tree(struct TreeNode *Node){

      if(Node == NULL){
        return;
      }

      display_binary_tree(Node->left);
      cout<<Node->val<<" ";
      display_binary_tree(Node->right);
    }

int get_height(TreeNode* node){

    if(!node){
        return -1;
    }

    int left = get_height(node->left);
    int right = get_height(node->right);

    return max(left+1 , right+1);
}

void answer(TreeNode* node , int r , int c ,vector<vector<string>>&vec , int height){

    if(!node){
        return;
    }

    vec[r][c] = to_string(node->val);
    answer(node->left , r+1 ,c- pow(2,height-r-1)  ,vec , height);
    answer(node->right , r+1, c+ pow(2,height-r-1) ,vec , height);
}

vector<vector<string>> printTree(TreeNode* root) {
    int height = get_height(root);
    int rows= height+1,  cols = pow(2,height+1)-1;
    vector<vector<string>>vec(rows , vector<string>((cols) , ""));

    int r = 0, c= (cols-1)/2;

    answer(root , r ,c , vec, height);
    
    return vec; 
}   

int code(){
    //code here 
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right= new TreeNode(4);
    root->right = new TreeNode(3);
    printTree(root);
    // display_binary_tree(root);
    // cout<<get_height(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
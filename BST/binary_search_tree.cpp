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

TreeNode* convertTotree(vector<int>vec){
  int index = 0;
  TreeNode*root = new TreeNode(vec[index++]);
  queue<TreeNode*>q;
  q.push(root);

  while(!q.empty() && index != vec.size()){

    //for left
    if(vec[index] == INT_MIN){
      index++;
    }
    else{
      q.front()->left = new TreeNode(vec[index++]);
      q.push(q.front()->left);
    }

    // for right
    if(vec[index] == INT_MIN){
      index++;
    }
    else{
      q.front()->right = new TreeNode(vec[index++]);
      q.push(q.front()->right);
    }
    q.pop();
  }

  return root;
}


void level_order_traversal(TreeNode *root){

    queue<TreeNode*>q;
    vector<int>answer;
    q.push(root);

    while(!q.empty()){

        if(q.front()->left != NULL){
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        answer.push_back(q.front()->val);
        q.pop();
    }

    for(auto i:answer){
        cout<<i<<" ";
    }
}

TreeNode* searchBST(TreeNode* root, int val) {
      while(root){
          if(root->val == val){
              return root;
          }

          else if(val < root->val){
              root = root->left;
          }
          else{
              root = root->right;
          }
      }
      return NULL;
  }
  TreeNode* insertIntoBST(TreeNode* head, int val) {
        if(!head){
            head = new TreeNode(val);
            return head;
        }
        TreeNode* root = head;
        TreeNode* L = NULL , *R = NULL;
            while(root){
                if(val < root->val){
                    L = root;
                    R= NULL;
                    root = root->left;
                }
                else{
                    R= root;
                    L= NULL;
                    root = root->right;
                }
            }
        if(L){
            L->left = new TreeNode(val);
        }
        else{
            R->right = new TreeNode(val);
        }
        return head;
    }

    
    /*
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


TreeNode *findPredecessor(TreeNode *node){
  TreeNode *t= node;
  node= node->left;
  while(node->right != NULL && node->right !=  t){
      node = node->right;
    }
    return node;
}



*/



int main(){
  vector<int>vec={1,INT_MIN,2,INT_MIN,3,INT_MIN,4};
  TreeNode* root = convertTotree(vec);
  BST_balancing(root);
//   level_order_traversal(root);
}

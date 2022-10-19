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

  TreeNode* findPredecessor(TreeNode* root , TreeNode* key){
    TreeNode* p= NULL;
    if(!root)
        return p;
    TreeNode* head = root;

    while(head){
        if(head->val == key->val){
            if(head->left){
                TreeNode *T = head->left;
                while(T->right){
                    T= T->right;
                }
                p = T;
            }
            return p;
        }
        else if(key->val < head->val){
            head = head->left;
        }
        else{
            p = head;
            head = head->right;
        }
    }
    return p;
  }
  TreeNode* findSuccessor(TreeNode* root , TreeNode* key){
    TreeNode* s= NULL;
    if(!root)
        return s;
    TreeNode* head = root;

    while(head){
        if(head->val == key->val){
            if(head->right){
                TreeNode* T = head->right;
                while(T->left){
                    T = T->left;
                }
                s = T;
            }
            return s;
        }
        else if(key->val < head->val){
            s= head;
            head = head->left;
        }
        else{
            head = head->right;
        }
    }
    return s;
  }

  TreeNode* deleteNode(TreeNode* root, int key) {
       if(!root)
           return root;
        TreeNode* head = root;
            if(head->val == key){

                //for 2 children
                if(head->right && head->left){
                    TreeNode* suc = findSuccessor(root , head);
                    head->val = suc->val;
                    head->right = deleteNode(head->right , suc->val);
                    return head;
                }
                //for 1 children
                if(head->right && head->left == NULL){
                    TreeNode* T = head->right;
                    delete(head);
                    return T;
                }
                else if(head->left && head->right == NULL){
                    TreeNode* T = head->left;
                    delete(head);
                    return T;
                }

                // leaf node
                else{
                    return NULL;
                }
            }
            else if(key < head->val)
            {
                head->left = deleteNode(head->left , key);
                return head;
            }
            else{
                head->right = deleteNode(head->right , key);
                return head;
            }
        return root;
    }

int code(){
    //code here
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
}

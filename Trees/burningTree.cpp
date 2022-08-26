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

    unordered_map<TreeNode*,TreeNode*> mapping_ParentToChild(TreeNode *node , int target , TreeNode *&targetNode){
        unordered_map<TreeNode*,TreeNode*>m;
        queue<TreeNode*>q;
        q.push(node);
        int size = q.size();

        while(!q.empty()){
            
            size = q.size();
            for(int i=0; i<size ; i++){
                TreeNode *temp = q.front();
                if(temp->val == target){
                    targetNode = temp;
                }
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    m[temp->left]=temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    m[temp->right]=temp;
                }
            }
        }
        return m;
    }

    int solve(queue<TreeNode*>q , unordered_map<TreeNode*,TreeNode*>m , unordered_set<TreeNode*>visited  , int Time){

        /* if(visited.find(q.front()) != visited.end()){
            q.pop();
            return;
        }
        if(Time <= check){
            Time = check;
        }

        TreeNode *num = q.front();
        q.pop();
        visited.insert(num);

        if(num->left){
            q.push(num->left);
            solve(q,m,visited,Time , check+1);
        }
        if(num->right){
            q.push(num->right);
            solve(q,m,visited,Time ,check+1);
        }
        if(m.find(num) != m.end()){
            q.push(m[num]);
            solve(q,m,visited,Time , check+1);
        } */

        while(!q.empty()){
            int size = q.size();
            bool check = false;
            for(int i=0;i<size ;i++){

                TreeNode *num = q.front();
                q.pop();
                visited.insert(num);

                 if(   (num->left )   &&   (visited.find(num->left) == visited.end())   ){
                    check = true;
                    q.push(num->left);
                }
                if(   (num->right)   &&   (visited.find(num->right) == visited.end())   ){
                    check = true;
                    q.push(num->right);
                }
                if(   (m.find(num) != m.end())   &&   (visited.find(m[num]) == visited.end())   ){
                    check = true;
                    q.push(m[num]);
                } 

                
            }
            if(check)
                Time++;
  }
        return Time;
    
    }

void burnTree(TreeNode *node , int target){
    TreeNode *targetNode;
    unordered_map<TreeNode*,TreeNode*>m = mapping_ParentToChild(node, target , targetNode);
    unordered_set<TreeNode*>visited;
    queue<TreeNode*>q;
    int time=0;
    q.push(targetNode);
    time = solve(q , m , visited  , time );
    cout<<time;

}

int code(){
    //code here 
    struct TreeNode *root= new TreeNode(1);
    root->left= new TreeNode(2);
    root->left->left= new TreeNode(3);
    root->left->left->left= new TreeNode(4);
    root->left->left->left->left= new TreeNode(5);
    /*
    root->left->right= new TreeNode(5);

    root->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->left->right=new TreeNode(8);
    root->right->left->left=new TreeNode(10);
    root->right->right= new TreeNode(7);
    root->right->right->right= new TreeNode(9);*/
    burnTree(root , 2);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
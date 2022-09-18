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

  struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr) , next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) , next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

int display(Node *head){
  Node *newNode  = head;

  if(newNode == NULL){
    cout<<"No data"<<endl;
    exit(0);
  }
  else{
    while(newNode != NULL){
      cout<<newNode->val<<'	';
      newNode= newNode->next;
    }
  }
  cout<<endl<<endl;
  }

    void display_binary_tree(struct Node *node){

          if(node == NULL){
            return;
          }

          display_binary_tree(node->left);
          cout<<node->val<<" ";
          display_binary_tree(node->right);
        }

    void level_traversal(Node* root){

      Node *node = NULL;
      while(root){
        node = root;
        root = root->left;
        while(node){
          cout<<node->val<<" ";
          node= node->next;
        }
        cout<<"# ";
      }
    }

    Node* connect(Node *root){
      if(!root ){
        return root;
      }

      int size;
      queue<Node*>q;
      Node* element = NULL , *prev = NULL;
      q.push(root);

      while(!q.empty()){
        size = q.size();

        for(int i= 0 ; i < size ; i++){
          element = q.front();
          q.pop();

          if(prev){
            prev->next = element;
          }
          prev = element;

          if(element->left){
            q.push(element->left);
          }
          if(element->right){
            q.push(element->right);
          }
        }
        prev = NULL;
      }
      return root;
    }

    int code(){
      //code here

      Node *head = new Node(1);
      head->left = new Node(2);
      head->left->left = new Node(4);
      head->left->right = new Node(5);

      head->right = new Node(3);
      // head->right->left = new Node(6);
      head->right->right = new Node(7);

      // display(root);
      // display_binary_tree(head);
      Node *node = connect(head);
      level_traversal(node);

      return 0;
    }

    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

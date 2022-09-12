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
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int display(Node *head){
    Node *newNode  = head;

    if(newNode == NULL){
        cout<<"No data"<<endl;
        exit(0);
    }
    else{
        while(newNode != NULL){
            cout<<newNode->data<<'\t';
            newNode= newNode->next;
        }
    }
    cout<<endl<<endl;
}

Node* removeDuplicates( Node *head)
{
    unordered_set<int>s;
    Node* prev = NULL,*current= head;

    if(!current || !(current->next)){
        return current;
    }

    while (current) {
      /* code */
      if(s.find(current->data) == s.end()){
        s.insert(current->data);
        prev = current;
      }
      else{
        prev->next = current->next;
        delete(current);
      }
      current= prev->next;
    }

    return head;
}

int code(){
    //code here
    Node *root = NULL;
    root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(3);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(5);
    display(root);

    Node* node = removeDuplicates(root);
    display(node);

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
}

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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  int display(ListNode *head){
    ListNode *newNode  = head;

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
ListNode* detectLoop(ListNode *root){
  ListNode *slow = root , *fast = root;

  if(!fast){
    return NULL;
  }
  else if(!(fast->next)){
    return NULL;
  }
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      return fast;
    }
  }
  return NULL;
}

ListNode *getHead_loop(ListNode *head , ListNode *point){
    ListNode *node = head;

    while(node != point){
      node = node->next;
      point = point->next;
    }

    return node;
}
    int code(){
      //code here
      ListNode* head =  new ListNode(1);
      head->next =  new ListNode(2);
      head->next->next =  new ListNode(3);
      head->next->next->next =  new ListNode(4);
      head->next->next->next->next =  new ListNode(5);

      head->next->next->next->next->next = head->next->next->next;

      ListNode* node = detectLoop(head);

      if(node){
        cout<<getHead_loop(head  , node)->val;
      }
      else{
        cout<<"No loop"<<endl;
      }
    }
    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

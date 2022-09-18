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

    int getLength(ListNode *head){
      int count =0;
      ListNode* node = head;

      while(node){
        count++;
        node = node->next;
      }

      return count;
    }


    // stack method
    void reorderList(ListNode* head) {
      if(!head)
        return;
      else if(!(head->next))
        return;
      else if(!(head->next->next))
        return;

      int length = getLength(head);
      stack<ListNode*>s;
      ListNode* prev = NULL;
      int k;

      if(length % 2){
        k= length/2;
      }
      else{
        k = (length/2)-1;
      }


      while(k--){
        s.push(head);
        prev = head;
        head= head->next;
      }

      if(length % 2){
        prev = head;
        head= head->next;
      }
      else{
        prev = prev->next->next;
        head= head->next->next;
      }


      while(!s.empty() && head != NULL){
          prev->next = head->next;
          head->next = s.top()->next;
          s.top()->next = head;

          head= prev->next;
          s.pop();
      }
    }


    //recursion method
    /* void solve(ListNode* head , ListNode* &first , int &k){
      if(head->next == NULL)
        return;

      solve(head->next , first , k);

      if(k > 0){
        ListNode* address = first->next;
        first->next = head->next;
        first->next->next = address;

        head->next = NULL;
        k--;
        first = first->next->next;
      }

      return;

    }

    void reorderList(ListNode* head) {

      if(!head)
        return;
      else if(!(head->next))
        return;
      else if(!(head->next->next))
        return;
      int length = getLength(head);
      int k;
      ListNode *first = head;

      //odd
      if(length % 2)
        k = (length/2);

      //even
      else
        k = (length/2)-1;

      solve(head , first , k);

    } */

    int code(){
      //code here
      ListNode *root = NULL;
      root = new ListNode(1);
      root->next = new ListNode(2);
      root->next->next = new ListNode(3);
      root->next->next->next = new ListNode(4);
      root->next->next->next->next = new ListNode(5);
      root->next->next->next->next->next = new ListNode(6);
      display(root);
      reorderList(root);
      display(root);
      return 0;
    }

    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

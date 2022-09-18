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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL , *nex = NULL , *current = head ;
        int flag=0, position=1;
        stack<ListNode*>s;

        if(!head){
          return head;
        }

        while(current && position < left){
          prev = current;
          current = current->next;
          position++;
        }

        if(!current){
          return head;
        }
        s.push(current);
        position++;
        current= current->next;
        while(current && position <= right){
          s.push(current);
          position++;
          current= current->next;
        }
        if(!current && position != (right+1)){
          return head;
        }


        nex = s.top()->next;
        current = s.top();
        if(prev){
          prev->next = current;
        }
        else{
          head = current;
        }
        s.pop();
        while(!s.empty()){
          current->next = s.top();
          current = s.top();
          s.pop();
        }
        current->next = nex;

        return head;

    }

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
      ListNode *node = reverseBetween(root , 1 , 1 );
      display(node);
      return 0;
    }

    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

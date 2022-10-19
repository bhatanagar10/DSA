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

    void insertNode(ListNode *&head , int value){

      if(!head){
        head = new ListNode(value);
        return;
      }
      ListNode *T = head;
      while(T->next){
        T = T->next;
      }
      T->next = new ListNode(value);
    }

    ListNode* mergeNodes(ListNode *head) {
        if(!head)
            return head;
        else if(!(head->next))
            return head;

        head = head->next;
        ListNode *current = head,*prev =NULL;
        int sum =0;
        while(current){
          if(current->val == 0){
            if(!prev){
              head = current;
              prev = head;
            }
            else{
              prev->next = current;
              prev = current;
            }
            current->val = sum;
            sum=0;
          }
          else
            sum+=current->val;

          current= current->next;
        }
        return head;

    }
      int code(){
        //code here
        ListNode *head = NULL;
        vector<int>vec={0,3,1,0,5,2,0};
        for(auto i: vec){
          insertNode(head , i);
        }
        display(head);
        ListNode*node = mergeNodes(head);
        display(node);
        return 0;
      }

    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

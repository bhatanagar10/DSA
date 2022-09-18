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

    ListNode* reverseList(ListNode* head) {
       ListNode *L= NULL , *M = NULL , *R = NULL;

        if(head == NULL || head->next == NULL)
            return head;

        L = head;
        M= head->next;
        R= head->next->next;
        L->next = NULL;
        while(R){
            M->next = L;

            L = M;
            M = R;
            R= R->next;
        }

        M->next = L;

        return M;

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

      ListNode* node = reverseList(root);

      display(node);

      return 0;
    }

    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

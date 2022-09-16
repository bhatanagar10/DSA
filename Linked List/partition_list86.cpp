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

    ListNode* partition(ListNode* head, int x) {
      
    }

/*
    ListNode* partition(ListNode* head, int x) {
      ListNode *prev1= NULL , *prev2= NULL, *current1 = head , *current2 = NULL;
      if(!head){
        return head;
      }

      while(current1){

        if(current1->val >= x){
          current2= current1->next;

          while(current2){

              while(current2->val >= x){
                prev2 = current2;
                current2 = current2->next;
                if(!current2){
                  break;
                }
              }
              if(current2){
                if(prev1){
                  if(prev2){
                    prev2->next = current2->next;
                    prev1->next = current2;
                    current2->next = current1;

                  }
                  else{
                    current1->next = current2->next;
                    prev1->next = current2;
                    current2->next = current1;
                  }
                }// end if
                else{
                  if(prev2){
                    prev2->next = current2->next;
                    head = current2;
                    current2->next = current1;

                  }
                  else{
                    current1->next = current2->next;
                    head= current2;
                    current2->next = current1;
                  }
                }//end else

                prev1 = current2;
                current2 = (prev2 == NULL)? current1->next : prev2->next;
            }
          }// end while(current2)
          break;

      }// end if check condition
        prev1 = current1;
        current1= current1->next;
    }// end while(curren1)


      return head;
    }
*/
    int code(){
      //code here
      ListNode *root = NULL;
      root = new ListNode(1);
      root->next = new ListNode(4);
      root->next->next = new ListNode(3);
      root->next->next->next = new ListNode(0);
      root->next->next->next->next = new ListNode(5);
      root->next->next->next->next->next = new ListNode(2);

      display(root);
      ListNode* node = partition(root , 2);
      display(node);
      return 0;
    }

    int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      code();
      return 0;
    }

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
            cout<<newNode->val<<'\t';
            newNode= newNode->next;
        }
    }
    cout<<endl<<endl;
 } 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *root = NULL, *node= NULL;
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        while(list1 || list2)
        {   
            int x = (list1 == NULL) ? INT_MAX : list1->val;
            int y = (list2 == NULL) ? INT_MAX : list2->val;

            if(x<=y){
                if(!root){
                     root = new ListNode(x);
                    node = root;
                }
                else{
                    node->next = new ListNode(x);
                    node= node->next;
                }
                list1= list1->next;
            }
            else{
                if(!root){
                     root = new ListNode(y);
                    node = root;
                }
                else{
                    node->next = new ListNode(y);
                    node= node->next;
                }
                
                list2= list2->next;
            }

        }
        
        return root;
    }

int code(){
    //code here 
    ListNode *l1= NULL , *l2 = nullptr;

    l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    l1->next->next->next = new ListNode(7);

    l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    l2->next->next->next = new ListNode(8);

    ListNode *root = mergeTwoLists(l1,l2);
    display(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
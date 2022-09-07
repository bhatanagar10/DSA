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

 ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode *node = head,*prev = NULL;

        if(!node){
            return node;
        }
        else if(node->next == NULL){
            return node;
        }

        // get size 
        int size = 0;
        while(node){
            node= node->next;
            size++;
        }
        node= head;
        int i = k%size;

        // for i roatations
        while(i--){

            if(prev == NULL){

               while(node->next->next !=  NULL){
                    prev = node;
                    node = node->next;
                }

                node->next->next = head;
                head = node->next;
                node->next = NULL;
                
                node = head;
            }
            else{
                prev->next->next = head;
                head = prev->next;
                prev->next = NULL;

                prev = NULL;
            }
        }

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
    ListNode *node = rotateRight(root , 11);
    display(node);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
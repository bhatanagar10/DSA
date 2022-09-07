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

ListNode* reverseKGroup(ListNode* head, int k) {

	ListNode *root = NULL, *prev= NULL , *node = head,*nex = NULL;
	stack<ListNode*>s;

 	if(!head){
 		return root;
 	}

 	while(node){
 		int count = k;
 		ListNode *temp = node;
 		while(count-- && temp){
 			s.push(temp);
 			temp= temp->next;
 		}

 		// if k groups were not possible
 		if(count != -1){
 			// if previous node is NULL
 			if(!prev){
 				root = node;
 			}
 			else{
 				prev = node;
 			}
 		}

 		// k groups are there
 		else{
 			nex = s.top()->next;
 			ListNode *t;

 			// if previous node is NULL
 			if(!prev){
 				t = root = s.top();
 				s.pop();
 			}
 		
 			else{
 				t = prev;
 			}
 				
 			while(!s.empty()){
 				t->next= s.top();
 				s.pop();
 				t = t->next;
 			}
 			prev= node;
 			node->next = nex;
 			
 		}
 		node = node->next;

 	}

    return root;
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


    ListNode *node = reverseKGroup(root , 3);
    display(node);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}

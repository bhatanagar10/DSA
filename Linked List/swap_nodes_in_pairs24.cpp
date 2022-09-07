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

ListNode* swapPairs(ListNode* head) {
	ListNode *node = head , *root = NULL, *x = NULL;

	// zero nodes
	if(!head){
		return root;
	}
    // if 1 node
    if(head->next == NULL){
        return head;
    }
	while(node && node->next){

		ListNode* y = node;
		ListNode* z = node->next;
		y->next = z->next;
		z->next = y;

		if(x != NULL){
			x->next = z;
		}

		root = (root == NULL) ? z : root;
		x = node;
		node = node->next;
	}

	return root;
}

int code(){
    //code here 
	ListNode *l1= NULL;

    l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    l1->next->next->next = new ListNode(7);
    display(l1);
    ListNode* root = swapPairs(l1);
    display(root);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
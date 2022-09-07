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

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp =head;
        int size=0;
        while( temp ){
            size++;
            temp= temp->next;
        }
        int count = size - n;
        ListNode *prev= NULL;
        temp = head;
        while(count){
            prev= temp;
            temp=temp->next;
            count--;
        }
        
        if(prev){
            prev->next = temp->next; 
        }
        else{
            head= NULL;

        }
        return head;
    }

int code(){
    //code here
    ListNode *root= new ListNode(1);
    
    display(removeNthFromEnd(root , 1));
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
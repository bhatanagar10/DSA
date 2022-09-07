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


/*                                                              priority queue method                              */
/*
Time complexity:- O(nlogK) k= number of lists and n number of nodes in final linked list
Space complexity:- O(n) n= space of priority queue

struct compare
{
    bool operator()(struct ListNode* a, struct ListNode* b)
    {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue< ListNode*,vector<ListNode*>,compare >q;
    ListNode *root = NULL , *node = NULL;

    for(int i=0; i < lists.size() ; i++){
        if(lists[i]!=NULL)
            q.push(lists[i]);
        
    }

    while(!q.empty()){
        
        ListNode *T= q.top();
        if(!root){
            root= new ListNode(T->val);
            node = root;
        }
        else{
            node->next = new ListNode(T->val);
            node = node->next;
        }

        q.pop();
        if(T->next){
            q.push(T->next);
        }
        
    }

    return root;
}
*/


/*                                        Divide and conquer                                         
Time complexity:- O(nlogK) k= number of lists and n number of nodes in final linked list
Space complexity:- O(1) */

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

ListNode* mergeKLists(vector<ListNode*>& lists){

    int start = 0 , end = lists.size()-1;
    while(start < end){
        int s = start;
        int e = end;

        while(s < e){
            lists[s] = mergeTwoLists(lists[s] , lists[e]);
            s++;
            e--;
        }

        end = e;
    }

    return lists[0];

}

int code(){

    int N = 3;
 
    int K = 4;
 
    vector<ListNode*>arr(N);
 
    arr[0] = new ListNode(1);
    arr[0]->next = new ListNode(3);
    arr[0]->next->next = new ListNode(5);
    arr[0]->next->next->next = new ListNode(7);
 
    arr[1] = new ListNode(2);
    arr[1]->next = new ListNode(4);
    arr[1]->next->next = new ListNode(6);
    arr[1]->next->next->next = new ListNode(8);
 
    arr[2] = new ListNode(0);
    arr[2]->next = new ListNode(9);
    arr[2]->next->next = new ListNode(10);
    arr[2]->next->next->next = new ListNode(11);


    //display all
    for(int i=0; i <N; i++){
        ListNode *temp = arr[i];
        while(temp){
            cout<<temp->val<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }

    cout<<endl;
    ListNode *root = mergeKLists(arr);
    cout<<"Merged List is:- ";
    display(root);
 
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

struct str{
    int data;
    struct str *address;
};

int insert_at_beginning(str *&head,int data){
    struct str *newNode  = new str();
    newNode->data = data;

    if(head == NULL){
        head = newNode;
        newNode->address = NULL;    
    }
    else{
        newNode->address= head;
        head = newNode;
    }
    return 0;
}

int display(struct str *head){
    struct str *newNode  = head;

    if(newNode == NULL){
        cout<<"No data"<<endl;
        exit(0);
    }
    else{
        while(newNode != NULL){
            cout<<newNode->data<<'\t';
            newNode= newNode->address;
        }
    }
    cout<<endl<<endl;
    
}

pair<int,str *>add(str *l1 , str *l2){
    int carry =0;

    if(l1 == NULL && l2== NULL){
        str *newNode = NULL;
        return make_pair(carry,newNode);
    }

    pair<int, str *> p = add(l1->address , l2->address);

    int sum = l1->data + l2->data + p.first;

    int m=sum % 10;    
    insert_at_beginning(p.second , m);
    sum=sum/10;   
    carry  = sum;

    return make_pair(carry,p.second);

}

void add_linked_list(str *l1,str*l2){
    pair<int, str *> p = add(l1->address,l2->address);

    int sum = l1->data + l2->data + p.first;
    insert_at_beginning(p.second , sum);

    display(p.second);
}

int code(){
    //code here 
    str *l1 = NULL,*l2 = NULL;

    int arr[]={1,2,3,4,5,6,7,8};

    insert_at_beginning(l1,arr[0]);
    insert_at_beginning(l1,arr[1]);
    insert_at_beginning(l1,arr[2]);
    insert_at_beginning(l1,arr[3]);
 
    insert_at_beginning(l2,arr[4]);
    insert_at_beginning(l2,arr[5]);
    insert_at_beginning(l2,arr[6]);
    insert_at_beginning(l2,arr[7]);
    display(l1);
    display(l2);
    add_linked_list(l1,l2);

    return 0;
}

int main(){
    code();
    return 0;
}
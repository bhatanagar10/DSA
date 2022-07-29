#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *address;
};

int insert_at_beginning(int data, Node *head){
    struct Node *newNode  = new Node();
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

void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->address;
    }
    printf("\n");
}

int compare(Node *head1 , Node *head2){
    int count1=0, count2=0;
    Node *p1 = head1;
    Node *p2 = head2;
    int carry = 0;

    while(head1 != NULL){
        count1++;
        head1= head1->address;
    }

    while(head2 != NULL){
        count2++;
        head2= head2->address;
    }

    if(count1 == count2){
        while(head1 != NULL){
            if(head1->data != head2->data){
                if(head1->data > head2->data){
                    subtractLinkedList(head1, head2, carry);
                }
                else{
                    subtractLinkedList(head2, head1, carry);
                }
            }
            head1= head1->address;
            head2 = head2->address;
        }
    }

    else if(count1 > count2){

        while(count1-count2 == 0){
            insert_at_beginning(0, head2);
            count2++;
        }
        subtractLinkedList(head1, head2, carry);
    }
    else{

        while(count2-count1 == 0){
            insert_at_beginning(0, head1);
            count1++;
        }
        subtractLinkedList(head2, head1, carry);
    }
}

struct Node *subtractLinkedList( Node *head1 , Node *head2 , int &carry){

    Node *p = NULL;
    if(head1->address  == NULL){
        return p;
    }

    p = subtractLinkedList(head1->address , head2->address, carry);
    Node *newNode = new Node();

    if(head1->data - carry >= head2->data){
        
        newNode->data = (head1->data-carry) - head2->data;
        newNode->address= p;
        p = newNode;
        carry = 0;

        return p;
        
    }
    else{

        carry = 1;    
        newNode->data = (head1->data - carry + 10) - (head2->data);
        newNode->address= p;
        p= newNode;

        return p;
        
    }
}

int main()
{
    Node* head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(0);
 
    Node* head2 = newNode(1);
 
    Node* result = compare(head1, head2);
 
    printList(result);
 
    return 0;
}
 
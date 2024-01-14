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
struct str *head = NULL;

int insert_at_beginning(int data){
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

int insert_at_end(int data){
        struct str *newNode  = new str();
        newNode->data = data;
        
        struct str *loop = head;

    if(loop == NULL){
        head = newNode;
        newNode->address = NULL;  
    }
    else{
        while(loop->address != NULL){
            loop= loop->address;
        }
        loop->address = newNode;
        newNode->address =NULL;
    }

}

int insert_after_specific_node(int data , int new_data){
    struct str *newNode = new str();
    newNode->data = new_data;
    
    struct str *loop = head;

    while(loop->data != data){
        loop = loop->address;
    }

    newNode->address = loop->address;
    loop->address = newNode;


}

int delete_at_beginning(){
    struct str *p = head;

    if(head != NULL){
        head = head->address;
    }
    delete(p);

    return 0;
}

int delete_at_end(){
    
struct str *loop = head;
struct str *pre = NULL;

    if(loop != NULL){
        while(loop->address != NULL){
            pre = loop;
            loop = loop->address;
        }

    pre->address = NULL;
    delete(loop);


    }

    return 0;
}

int delete_after_specific_node(int n){
    struct str * loop = head;
    struct str *pre = NULL;

    while( loop != NULL && n >0){
            pre = loop;
            loop =  loop->address;
            n--;
        }
    
    if(n ==0 ){
        pre->address = loop->address;
        delete(loop);
    }

    return 0;
}

int display_reverse(struct str *current){

    if(head == NULL){
         cout<<"List empty"<<endl;

         return 0;
    }

    else{
        if(current->address != NULL){
            display_reverse(current->address);
        }

        cout<<current->data<<'\t';
    }


    //base condition
    if(!current){
        return;
    }

    display_reverse(current->address);
    cout<<current->data<<" ";

}

str *reverse_list_recursion(struct str *arr){
    if(arr->address == NULL){
        head = arr;
        return arr;
    }

    struct str *node = reverse_list_recursion(arr->address);
    node->address = arr;
    arr->address= NULL;
    return(arr);

}

int reverse_list(struct str *current){

    struct str *rev = reverse_list_recursion(current);

    /* 
    struct str *pre= NULL;
    struct str *next = NULL;

    while(current!= NULL){
        next = current->address;
        current->address = pre;

        pre=current;
        current = next;

    }

    current = pre; */
    return 0;
}

void findMid(struct str *arr , struct str *&mid , bool &oddEven ){
    struct str *s=arr,*f=arr;


    while(f != NULL && f->address != NULL){
        s= s->address;
        f= f->address->address;
    }

    if(f){
        oddEven = true;
    }

    mid = s;
}

struct str *reverse_pallindrome(struct str *p){
    struct str *start = NULL;

    while(p != NULL){
        struct str *next = p->address;

        p->address = start;
        start = p;
        p= next;
    }

    return start;
}

bool comparison(struct str *head , struct str *tail){

    while(head != NULL && tail != NULL){
        if(head->data != tail->data){
            return false;
        }
        head= head->address;
        tail = tail->address;
    }
    return true;
}

int check_palindrome(){

    struct str *mid = NULL; 
    bool oddEven = false;
    findMid(head , mid , oddEven);

    if(oddEven){
        mid=mid->address;
    }
    //cout<<mid->data<<endl;
    struct str* start = reverse_pallindrome(mid);

    bool isPallindrome = comparison(head , start);

    if(isPallindrome){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}

int linked_list(){
    //default-linked-list
    int i=1;
    while(i<=10){
        insert_at_beginning(i);
        i++;
    }
    display(head);

    int option; char response;
    do {
        cout<<"-------------------------------Menu--------------------"<<"\n";
        cout<<"1. Insert_at_end"<<endl;
        cout<<"2. Insert_after_specific_node"<<endl;
        cout<<"3. Delete from beginning"<<endl;
        cout<<"4. Delete at end"<<endl;
        cout<<"5. Delete after specific node"<<endl;
        cout<<"6. Display Reverse"<<endl;
        cout<<"7. Reverse list"<<endl;
        cout<<"8. Check Pallindrome"<<endl;

        cin>>option;
        switch (option)
        {
            case 1:
                insert_at_end(20);
                display(head);
                break;

            case 2:
                insert_after_specific_node(5,20);
                display(head);
                break;

            case 3: 
                delete_at_beginning();
                display(head);
                break;

            case 4:
                delete_at_end();
                display(head);
                break;

            case 5:
                delete_after_specific_node(5);
                display(head);
                break;

            case 6: 
                display_reverse(head);
                cout<<endl;
                break;

            case 7: 
                reverse_list(head);
                display(head);
                break;

            case 8:
                check_palindrome();          
                break;

            case 9: 
                subtraction();
                break;

            default:
                break;
        }
        cout<<"Again (Y/N)"<<'\t';
        cin>>response;

    }while(response == 'Y' || response == 'y');

    
    return 0;
}

int code(){
    //code here 
    linked_list();
    return 0;
}

int main(){
    code();
    return 0;
}
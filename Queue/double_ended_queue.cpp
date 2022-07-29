#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;
#define N 10

class Queue{

    int *arr = new int[N];
    int front;
    int rear;

    public:

    Queue(){
        front =-1;
        rear = -1;
    }

    void push_back(int element){

        if(  (front == 0 && rear == N-1) && ( rear == front -1 )  ){
            cout<<"Queue full"<<endl;
            return;
        }
        else if(front == -1 && rear == -1){
            front =0 ;
            rear =0;
        }
        else if(rear == N-1){
            rear =0;
        }
        else{
            rear++;
        }

        arr[rear] = element;
    }    

    void push_front(int element){

        if(  (front == 0 && rear == N-1) && ( rear == front -1 )  ){
            cout<<"Queue full"<<endl;
            return;
        }
        else if(front == -1 && rear == -1){
            front =0 ;
            rear =0;
        }
        else if(front == 0){
            front = N-1;
        }
        else{
            front--;
        }

        arr[front] = element;
    }    

    void pop_front(){
        if(front == -1){
            cout<<"Queue empty"<<endl;
            return;
        }
        else if(front == rear){
            front == -1;
            rear == -1;
        }
        else if(front == N-1){
            front = 0;
        }
        else{
            front++;
        }
    }

    void pop_rear(){
        if(front == -1){
            cout<<"Queue empty"<<endl;
            return;
        }
        else if(front == rear){
            front == -1;
            rear == -1;
        }
        else if(rear == 0){
            rear = N-1;
        }
        else{
            rear--;
        }
    }

    void display(){
        if(front == -1){
            cout<<"Queue empty"<<endl;
            return;
        }
        if(front < rear){
            while(front < rear){
                cout<<arr[front]<<" ";
                front++;
            }
        }

        else{
            while(front <= N-1){
                cout<<arr[front];
                front++;
            }
            front =0;
            while(front <rear){
                cout<<arr[front]<<" ";
                front++;
            }
        }

    }

};

int code(){
    //code here 
    Queue q;
    q.push_back(10);
    q.push_back(20);
    q.push_front(30);
    return 0;
}

int main(){
    code();
    return 0;
}
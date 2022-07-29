#include<iostream>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

void bottom_of_stack(stack<int>&s , int k){

    if(s.empty()){
        s.push(k);
        return;
    }

    int num = s.top();
    s.pop();
    bottom_of_stack(s,k);
    s.push(num);

    return;
}

void Reverse_stack(stack<int>&s){
   if(s.empty()){
        return;
    } 

    int num = s.top();
    s.pop();
    Reverse_stack(s);
    bottom_of_stack(s,num);

    return;
}

int code(){
    //code here 

    stack<int>s;
    s.push(9);
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(8);


    Reverse_stack(s);

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

    return 0;
}

int main(){
    code();
    return 0;
}
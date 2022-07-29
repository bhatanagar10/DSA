#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

void sorting(stack<int>&s , int num){
    if(s.empty()){
        s.push(num);
    }
    else if(s.top() < num){
        s.push(num);
    }
    else{
        int x= s.top();
        s.pop();
        sorting(s,num);
        s.push(x);
    }
}

void sort_stack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    sort_stack(s);
    sorting(s,num);

}

int code(){
    //code here 
    stack<int>s;
    s.push(9);
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(8);

    sort_stack(s);

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
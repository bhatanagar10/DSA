/* in this program we have to find the minimum in a stack with time
complexity O(1) and O(1) space complexity */

/*  what we do is store the minimum during push() operation only 

if number during push() < , then we store the ( 2*num - min ) in stack */

/* during pop() if top() < min   */ 

#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<string>
#include<bits/stdc++.h>
#include"headerfiles/myFunctions.cpp"

using namespace std;

/*
class Stack{

    string element;
    int min;
    stack<int>s;

    public:
    Stack(){
        element ="";
        min =INT_MIN;
    }


    void Stack_push(int num){
        if(s.empty() || num < min){
            min = num;
            
        }
            element= to_string(min)+ element;
            s.push(num);

    }

    void Stack_getMin(){
        cout<<element[0]<<endl;
    }
    void Stack_pop(){
        if(s.empty()){
            cout<<"Empty stack"<<endl;
            return;
        }

        s.pop();
        element = element.substr(1);
    }

    void Stack_display(){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};
*/

class Stack{

    
    int min;
    stack<int>s;

    public:
    Stack(){
            min =INT_MIN;
    }


    void Stack_push(int num){
        if(s.empty()){
            min = num;      
            s.push(min);        
        }
        else if(num < min){
            s.push(2*num - min);
            min=num;
        }   
        else{
            s.push(num);
        }
            
    }

    void Stack_getMin(){
        cout<<min<<endl;
    }
    void Stack_pop(){
        if(s.empty()){
            cout<<"Empty stack"<<endl;
            return;
        }
        else if(s.top()< min){
            min = 2*min - s.top();
        }
        s.pop();
       
    }

    void Stack_display(){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};

int code(){
    //code here 
    Stack m;
    m.Stack_push(5);
    m.Stack_push(3);
    m.Stack_push(8);
    m.Stack_push(2);
    m.Stack_push(4);

    m.Stack_getMin();
    m.Stack_pop();
    m.Stack_getMin();
    m.Stack_pop();
    m.Stack_getMin();
    m.Stack_pop();
    m.Stack_getMin();
    m.Stack_pop();
    m.Stack_getMin();
    m.Stack_pop();
   



    //m.Stack_display();


    return 0;
}

int main(){
    code();
    return 0;
}
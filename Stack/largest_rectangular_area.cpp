/* largest rectangular area in histogram */
#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<list>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

list<int> prevsmallernumber(vector<int>vec){

   stack<int>s;
    list<int>result;
    s.push(-1);
    for(int i = 0 ; i < vec.size() ; i++){
        
            while(s.top() != -1 && vec[s.top()] >= vec[i]){
                s.pop();
            }
            if(s.top() == -1){
                result.push_front(0);    
            }
            else{
                result.push_front(s.top()+1);
            }
            s.push(i);
    
    }
    return result;
}

list<int> nextsmallernumber(vector<int>vec){
    stack<int>s;
    list<int>result;
    s.push(-1);
    for(int i = vec.size()-1 ; i >=0 ; i--){
        
            while(s.top() != -1 && vec[s.top()] >= vec[i]){
                s.pop();
            }
            if(s.top() == -1){
                result.push_front(vec.size()-1);    
            }
            else{
                result.push_front(s.top()-1);
            }
            s.push(i);
    
    }
    return result;
}

int largest_rectangle_area(vector<int>vec){

    list<int>next = nextsmallernumber(vec);
    list<int>prev = prevsmallernumber(vec);
    auto i = next.begin();
    auto j = prev.rbegin();
    int area = vec[0] * abs(*i - *j + 1);
    i++;
    j++;

    for(int k = 1 ; k <vec.size(); k++){
        int newArea = vec[k] * abs(*i - *j + 1  );

        if(area < newArea){
            area = newArea;
        }
        i++;
        j++;
    }
    return area;
}

/* int code(){
    //code here 
    vector<int>vec = {0,1,1,0};
    cout<<largest_rectangle_area(vec);
    return 0;
}

int main(){
    code();
    return 0;
} */
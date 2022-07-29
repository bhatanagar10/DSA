#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include <list>
#include<bits/stdc++.h>

using namespace std;

int code(){
    //code here 
    vector<int>vec = {2,1,4,3};
    /* using stack */
    stack<int>s;
    list<int>result;
    s.push(-1);
    for(int i = vec.size()-1 ; i >=0 ; i--){
        
            while(s.top() > vec[i]){
                s.pop();
            }
            result.push_front(s.top());
            s.push(vec[i]);
    
    }


        /* using list */
   /*  list<int>result;
    result.push_front(-1);
    int min = INT_MAX;

    for (int i = vec.size()-1; i >0; i--){

        if(vec[i] < min){
            min = vec[i];
        }
        result.push_front(min);

    }
*/
    for(auto i = result.begin() ; i != result.end() ; i++){
        cout<<*i;   
    } 
        
    return 0;
}

int main(){
    code();
    return 0;
}
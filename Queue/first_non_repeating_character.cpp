#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

void first_non_repeating_character(string str){
    map<char,int>count;
    queue<char>q;

    for(int i=0; i <str.length() ; i++){

        if(count.find(str[i]) == count.end()){
            q.push(str[i]);    
        }
        
        count[str[i]]++;

        while(count[q.front()] > 1){
            q.pop();
        }

        if(q.empty()){
            cout<<"#"<<" " ;
        }
        else{
            cout<<q.front()<<" ";
        }
    }
}

int code(){
    //code here 
    string str="abbac";
    first_non_repeating_character(str);
    return 0;
}

int main(){
    code();
    return 0;
}
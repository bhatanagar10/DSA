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

int firstNonRepeating(string str)
{
    int fi[256]; // array to store First Index
 
    // initializing all elements to -1
    for (int i = 0; i < 256; i++)
        fi[i] = -1;
 
    // sets all repeating characters to -2 and non-repeating
    // characters contain the index where they occur
    for (int i = 0; i < str.length(); i++) {
        if (fi[str[i]] == -1) {
            fi[str[i]] = i;
        }
        else {
            fi[str[i]] = -2;
        }
    }
 
    int res = INT_MAX;
 
    for (int i = 0; i < 256; i++) {
 
        // If this character is not -1 or -2 then it
        // means that this character occurred only once
        // so find the min index of all characters that
        // occur only once, that's our first index
        if (fi[i] >= 0)
            res = min(res, fi[i]);
    }
 
    // if res remains INT_MAX, it means there are no
    // characters that repeat only once or the string is
    // empty
    if (res == INT_MAX)
        return -1;
    else
        return res;
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
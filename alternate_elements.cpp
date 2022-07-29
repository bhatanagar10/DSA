/*  Print alternate elements , elemets should not repeat   */

#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

bool check_pallindrome(string str){

    string s = str;
    reverse(s.begin() , s.end());
    if(str == s){
        return true;
    }
    return false;
}

int code(){
    //code here 
    string str="aababaabce";
    int k=3;
    int count = k;
    for(int i = 0 ; i < str.size() - k ; i++){
        

        while(count +i <=str.size()){
            string s = str.substr(i,count);
            if(check_pallindrome(s)){
                cout<<s<<endl;
                i = i+(count-1);
                break;
            }

            count++;
        }
        count= k;
    
    }
    return 0;
}

int main(){
    code();
    return 0;
}
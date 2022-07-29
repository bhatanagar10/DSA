#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>
#include "headerfiles/myFunctions.cpp"

using namespace std;

void solve(string str , vector<string>&vec ,int index){

    if(index == str.length()-1){
        vec.push_back(str);
    }

    for(int i=index ; i <str.length() ; i++){
        swap(str ,i ,index);
        solve(str,vec ,index+1);
        swap(str ,i ,index);
        
    }

}

int code(){
    //code here 
    string str="abc";
    int index=0;
    vector<string>vec;
    solve(str,vec,index);
    for(auto i:vec){
        cout<<i<<" ";
    }
    return 0;
}

int main(){
    code();
    return 0;
}
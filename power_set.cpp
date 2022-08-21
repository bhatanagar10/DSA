#include<iostream>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

void power_set_string(string str){
    for(int  i= 0 ; i < pow(2,str.length()) ; i++){
        for(int  j = 0 ; j < str.length() ; j++){

            if( i & (1<<j)){
                cout<<str[j];
            }
        }
        cout<<endl;
    }
}

void power_set_int(vector<int>v){

    for(int  i= 0 ; i < pow(2,v.size()) ; i++){
        for(int  j = 0 ; j < v.size() ; j++){

            if( i & (1<<j)){
                cout<<v[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int code(){
    //code here

    string str= "abc";
    vector<int>v={1,2,3};
    power_set_string(str);
    //power_set_int(v);
    return 0;
}

int main(){
    code();
    return 0;
}

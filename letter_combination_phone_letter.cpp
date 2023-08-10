#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <typeinfo>

using namespace std;

 void combination(string digits , int index , vector<string>&answer ,unordered_map<char,string>mapping, string a){

    if(index == digits.length() || digits.length() == 0){
        answer.push_back(a);
        return;
    }

    string str =  mapping[digits[index]];
    for(int i=0; i < str.length() ; i++){
        a.push_back(str[i]);
        combination(digits , index+1 , answer , mapping , a);
        a.pop_back();
    }
 }

int code(){
    //code here 
    unordered_map<char,string>mapping;
    mapping['2']= "abc";
    mapping['3']= "def";
    mapping['4']= "ghi";
    mapping['5']= "jkl";
    mapping['6']= "mno";
    mapping['7']= "pqrs";
    mapping['8']= "tuv";
    mapping['9']= "wxyz";

    string digits="347";
    int index =0;
    vector<string>answer;
    string a;
    combination(digits , index , answer ,mapping,a);

    for(auto i : answer){
        cout<<i<<" ";
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
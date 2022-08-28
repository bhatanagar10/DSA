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

int findCandidate(vector<int>vec){

    int count =1, majority =vec[0];
    for(int i=1 ; i< vec.size(); i++){
        if(majority != vec[i]){
            count--;
        }
        else{
            count++;
        }


        if(count ==0){
            majority = vec[i];
            count++;
        }
    }
    return majority;
}

int code(){
    //code here 
    vector<int>vec={1,2,3,4,5,5,6,5};
    int candidate = findCandidate(vec);
    int c = count(vec.begin() , vec.end() , candidate);

    if(c > vec.size()/2){
        cout<<"Majority element:- "<< candidate;
    }
    else{
        cout<<"No majority element";
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
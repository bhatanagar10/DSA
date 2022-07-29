#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

vector<int> sliding_window_maxmin(vector<int>vec, int k){

    deque<int>max;
    deque<int>min;
    vector<int>result;

    for(int i = 0; i <k ; i++){ 

// for max 
        if(max.empty()){
            max.push_back(i);
        }

        while(!max.empty() && vec[i] > vec[max.back()]){
            max.pop_back();
        }
        max.push_back(i);


// for min
        if(min.empty()){
            min.push_back(i);
        }

        while(!min.empty() && vec[i] < vec[min.back()]){
            min.pop_back();
        }
        min.push_back(i);


    }

    result.push_back(vec[max.front()] + vec[min.front()]);

    for(int i = k ; i<vec.size(); i++ ){

// for max

        while(!max.empty() && max.front() < abs(k-i)+1 ){
            max.pop_front();
        }

        while(!max.empty() && vec[i] > vec[max.back()]){
            max.pop_back();
        }

        max.push_back(i);

// for min

        while(!min.empty() && min.front() < abs(k-i)+1 ){
            min.pop_front();
        }

        while(!min.empty() && vec[i] < vec[min.back()]){
            min.pop_back();
        }

        min.push_back(i);

        result.push_back(vec[min.front()] + vec[max.front()]);
    }

    return result;
}

int code(){
    
    //code here 
    vector<int>vec={2, 5, -1, 7, -3, -1, -2};
    int k=4;
    vector<int>result = sliding_window_maxmin(vec, k);
    for(auto i: result){
        cout<<i<<" ";
    }
    return 0;
}

int main(){
    code();
    return 0;
}
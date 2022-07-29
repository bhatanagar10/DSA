/* In this program we have to find maximum in a particular window of size k */

/* First we will work with first k elements, if size is zero then put index , 
else pop() elements that are out of window and pop() every element which is in queue and less than current element then pop() them, 
now front() is answer to that window*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

vector<int> sliding_window_maximum(vector<int>vec, int k){

    deque<int>q;
    vector<int>result;

    for(int i = 0; i <k ; i++){

        if(q.empty()){
            q.push_back(i);
        }

        while(!q.empty() && vec[i] > vec[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    result.push_back(vec[q.front()]);

    for(int i = k ; i<vec.size(); i++ ){

        while(!q.empty() && q.front() < abs(k-i)+1 ){
            q.pop_front();
        }

        while(!q.empty() && vec[i] > vec[q.back()]){
            q.pop_back();
        }

        q.push_back(i);

        result.push_back(vec[q.front()]);
    }

    return result;

}

int code(){

    //code here 
    vector<int>vec;
    vec.push_back(-8);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(-6);
    vec.push_back(10);

    int k=2;
    vector<int>result = sliding_window_maximum(vec,k);

    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}

int main(){
    code();
    return 0;
}
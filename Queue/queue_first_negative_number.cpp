/* In this program we have to find the first negative number in specified window size k */

/* in function we will use a deque<int> and we will get the negative  number for particular window at front() */

/* in this we will first take first k elements and put only negative numbers in this back() , then for next window we will remove those
index from queue who is not in window k and put new element if it is negative. push() it. 
If queue is empty() hten answer is zero */


#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

vector<int> first_negative_number(vector<int>vec, int k){

    deque<int>q;
    vector<int>result;

    for(int i = 0; i <k ; i++){
        if(vec[i] < 0){
            q.push_back(i);
        }
    }

    if(q.empty()){
        result.push_back(0);
    }

    else{
        result.push_back(vec[q.front()]);
    }


    for(int i = k ; i<vec.size(); i++ ){
        while(!q.empty() && q.front() < abs(k-i)+1 ){
            q.pop_front();
        }

        if(vec[i] < 0){
            q.push_back(i);
        }

        if(q.empty()){
            result.push_back(0);
        }
        else{
            result.push_back(vec[q.front()]);
        }
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
    vector<int>result = first_negative_number(vec,k);

    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}

int main(){
    code();
    return 0;
}
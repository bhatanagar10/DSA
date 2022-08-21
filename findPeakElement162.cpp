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

int solution(vector<int>& nums , int start , int end){

    if(s==e){
        return s;
    }
    int mid = (s+e)/2;

    if(nums[mid] > nums[mid+1]){
        solution(nums , start , mid);
    }
    else{
        solution(nums ,mid+1 , end);
    }    
}
    
    int findPeakElement(vector<int>& nums) {
        vector<int>vec;
        int s=0, e= nums.size()-1;
        solution(nums ,vec ,s , e );
        if(vec.size() != 0){
            return vec[0];
        }
        else{
            return 0;
        }
    }

int code(){
    //code here
    // cout<<findPeakElement(vec);
    vector<int>vec={1,2};
    cout<<findPeakElement(vec);
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
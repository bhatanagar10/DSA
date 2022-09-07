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

void solution(vector<int>& nums , vector<int>&vec , int start , int end){
        int s= start  , e= end;
    if(s>=e){
        return;
    }
    if(nums.size() == 2){
        vec.push_back(nums[0] > nums[1] ? 0 : 1);
        return;
    }
    int mid = (s+e)/2;

    while(s<e){
        if(nums[mid] > nums[mid+1]){
            e= mid;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    
        
    if( mid-1 >=0  && mid+1 <= nums.size()-1){
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            vec.push_back(mid);
        }
    }
        
    else if(mid == nums.size()-1)
            vec.push_back(mid); 
    else if(mid == 0)    
            vec.push_back(mid);
    
    solution(nums , vec, start , mid-1);
    solution(nums , vec , mid+1 , end);
    }
    
    void findPeakElement(vector<int>& nums) {
        vector<int>vec;
        int s=0, e= nums.size()-1;
        solution(nums ,vec ,s , e );

        for(auto i:vec){
            cout<<nums[i]<<" ";
        }
        /* if(vec.size() != 0){
            return vec[0];
        }
        else{
            return 0;
        } */
    }

int code(){
    //code here 
    vector<int>nums = {1,2,1,3,5,6,4};
    findPeakElement(nums);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
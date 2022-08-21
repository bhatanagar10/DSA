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

// linear O(N)
/* vector<int> searchRange(vector<int>& nums, int target) {
     vector<int>vec(2 ,-1);
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == target){

                if(vec[0] == -1){
                    vec[0] = vec[1] = i;  
                }
                
                else
                    vec[1] = i;              
            }
        }    
        return vec;        
} */

void FirstSolution(vector<int>& nums , int target , int start , int end , int &answer){
    if(start > end){
        return;
    }
   
    int mid= (start+end)/2;

    if((nums[mid] == target )){
        answer = mid;
    }

    if(target <=nums[mid]){
        FirstSolution(nums , target , start , mid-1 , answer);

    }
    else {
        FirstSolution(nums , target , mid+1  , end , answer);
    }
    return;
}


void SecondSolution(vector<int>& nums , int target , int start , int end , int &answer){
    if(start > end){
        return;
    }
    int mid= (start+end)/2;
    if( (nums[mid] == target )){
       answer =  mid;
    }

    if(target >=nums[mid]){
        SecondSolution(nums , target , mid+1 , end , answer);
    }
    else {
        SecondSolution(nums , target , start  , mid-1 , answer);
    }

    return;
}


//binary search O(logN)
vector<int> searchRange(vector<int>& nums, int target) {

    int start = 0 , end = nums.size()-1;
    int x=-1 ,y=-1;
    FirstSolution(nums , target , start , end ,x);
    SecondSolution(nums, target , start , end , y);
    vector<int>vec={x,y};
    return vec;
}

int main(){

    vector<int>nums={};
    vector<int>vec = searchRange(nums , 6);
    for(auto i:vec){
        cout<<i<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
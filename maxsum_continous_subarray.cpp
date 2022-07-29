#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;



//*************************** divide and conquere**********************************
/* 
int max(int a , int b){
        return (a>b)? a:b ;
    }
    
long long int midSum(vector<int>arr , int l , int h){
        int m = (l+h)/2;
        long long int sum_l=INT_MIN , sum_r = INT_MIN,sum =0;
        
        for(int i = m ; i>=0 ; i--){

            sum+= arr[i];
            if(sum > sum_l){
                sum_l = sum;
            }
        }
            sum=0;
        for(int i = m+1 ; i<=h; i++){
            sum+= arr[i];
            if(sum > sum_r){
                sum_r = sum;
            }
        }
         
        return  max(max(sum_r,sum_l),(sum_l + sum_r)) ;
                    
    }

int subArray(vector<int>arr, int l, int h){
        if(l==h){
            return arr[l];
        }
        
        int m = (l+h)/2;
        return max(subArray(arr , l , m) ,  
                   max(subArray(arr,m+1 ,h ),  
                       midSum(arr,l,h))
                       );
    } */

    //**********************************Kadane's algorithm ******************************//  

int subArray(vector<int>& nums, int l, int h){
    int sum_max=INT_MIN , sum=0;
    int start=0, end=0,check=0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
            
            if(sum_max < sum){
                sum_max = sum;
                start=check;
                end=i;
            }
            
            if(sum < 0){
                sum = 0;
                check++;
            }
        }
        cout<<"["<<'\t';
        for(int i = start ; i <=end ; i++){
            cout<<nums[i]<<'\t';
        }
        cout<<"]"<<endl;
        return sum_max;
} 



int maxSubArray(vector<int>& nums) {
        int result = subArray(nums, 0 , nums.size()-1); 

        return result;
    }


int code(){
    //code here 
    vector<int>nums={ -9,-8,-6,-4,-3,-1 };
 
    cout<<maxSubArray(nums);
    return 0;
}

int main(){
    code();
    return 0;
}
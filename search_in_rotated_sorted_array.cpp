#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

int peak_mountain_array(vector<int>arr,int k){
    int s = 0;
    int e = arr.size() - 1;
    int mid=0,flag=0;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == k ){
            flag = 1;
            return mid;
        }
        else if( k > arr[mid] &&  k<=arr[e]){
            s = mid+1;
        } 
        else{
            e = mid-1;
        }
    }

    if(!flag){
        cout<< "-1";
    }
}

int code(){
    //code here {
    vector<int>arr{7,9,1,2,3};
    /* for(int i=0 ; i < arr.size() ; i++){
        cout<<arr[i];
    } */
    cout<<arr[peak_mountain_array(arr,7)];
    return 0;
}

int main(){
    code();
    return 0;
}


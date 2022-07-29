#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

int peak_mountain_array(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid=0;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            s=arr.size();
            e=0;
        }
        else if(arr[mid] < arr[mid+1]){
            s = mid+1;
        } 
        else{
            e = mid-1;
        }
    }
    return mid;
}

int code(){
    //code here {
    vector<int>arr{3,5,3,2,0};
    /* for(int i=0 ; i < arr.size() ; i++){
        cout<<arr[i];
    } */
    cout<<arr[peak_mountain_array(arr)];
    return 0;
}

int main(){
    code();
    return 0;
}


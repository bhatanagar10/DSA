#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

int peak_mountain_array(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid=(s+e)/2;
    while(s<e){
            if(arr[mid] > arr[mid+1]){
                e= mid;
            }
            else{
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return mid;
}


int peak_mountain_array1(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid=(s+e)/2;
    while(s<e){
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return mid;
}

int code(){
    //code here {
    vector<int>arr{3,5,6,3,2,0};
    /* for(int i=0 ; i < arr.size() ; i++){
        cout<<arr[i];
    } */
    cout<<peak_mountain_array1(arr);
    return 0;
}

int main(){
    code();
    return 0;
}


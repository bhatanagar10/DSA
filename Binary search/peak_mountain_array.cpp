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

int code(){
    //code here {
    vector<int>arr{1,2,3,1};
    /* for(int i=0 ; i < arr.size() ; i++){
        cout<<arr[i];
    } */
    cout<<peak_mountain_array(arr);
    return 0;
}

int main(){
    code();
    return 0;
}


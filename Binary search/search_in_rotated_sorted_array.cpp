#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

int search_in_rotated_sorted_array(vector<int>arr,int k){
    int s = 0;
    int e = arr.size() - 1;
    int mid=0,flag=0;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == k ){
            flag = 1;
            return mid;
        }
        else if(arr[mid] >= arr[s]){
            if(k < arr[mid] && k>= arr[s])
                e= mid-1;
            else
                s= mid+1;
        }
        else{
            if(k >arr[mid] && k<= arr[e])
                s= mid+1;
            else    
                e=mid-1;
        }
    }

    if(!flag){
        cout<< "-1";
    }
}

int code(){
    //code here {
    vector<int>arr{5,6,7,1,2,3,4};

    cout<<search_in_rotated_sorted_array(arr,5);
    return 0;
}

int main(){
    code();
    return 0;
}


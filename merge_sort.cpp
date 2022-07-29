#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;


void merge(vector<int>&vec , int s , int e , int mid){
    vector<int>v1,v2;
    for(int i = s ; i <= mid ; i++){
        v1.push_back(vec[i]);
    }

    for(int i = mid+1 ; i <= e ; i++){
        v2.push_back(vec[i]);
    }

    int i = 0 , j = 0 , k = s;

    while( i < v1.size() && j < v2.size() ){
        if(v1[i] < v2[j]){
            vec[k] = v1[i];
            i++;
            k++;
        }
        else{
            vec[k] = v2[j];
            j++;
            k++;
        }
    }

    while( i < v1.size() ){
        vec[k] = v1[i];
            i++;
            k++;
    }

    while( j < v2.size() ){
        vec[k] = v2[j];
            j++;
            k++;
    }

}





void merge_sort(vector<int>&vec,int s , int e , int mid){
    if(s == e){
        return;
    }
    merge_sort(vec , s , mid , ( s+mid ) / 2 );
    merge_sort(vec , mid+1 , e , (mid+1+e)/2 );

    merge(vec , s, e, mid);

}

int code(){
    //code here 
    vector<int>vec = {2,1,9,6,4,7,5,8,3};
  
    merge_sort(vec,0,vec.size()-1,(0+vec.size()-1)/2);

     for(auto i: vec){
        cout<<i;
    }
   
    return 0;
}

int main(){
    code();
    return 0;
}
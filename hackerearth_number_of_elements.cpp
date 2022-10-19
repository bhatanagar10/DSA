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

  // returns index of numeber just greater than h
  int search_greater(vector<int>A , int h){
    int low = 0 , high = A.size()-1, mid;
    while(low <= high){
      mid = (low+high)/2;
        if(A[mid] == h){
          if(mid+1 < A.size())
            while(A[mid+1] == h){
              mid++;
            }
          return mid+1;
        }
        else if(A[mid] > h){
          high = mid-1;
        }
        else if(A[mid] < h){
          low = mid+1;
        }
    }
    return low;
  }

  void solve(vector<int>A , vector<int>h){
    sort(A.begin() , A.end());
    for(auto i: h){
      int index = search_greater(A, i);
      if(index >=A.size()){
        //zero elements greater
        cout<<0<<endl;
      }
      else{
        int count = A.size() - index;
        cout<<count<<endl;
      }
    }
  }

  int code(){
    //code here
    int n , k;
    cin>>n;
    vector<int>A(n);
    for(int i=0  ; i < n ; i++){
      cin>>A[i];
    }
    cin>>k;
    vector<int>h(k);
    for(int i=0  ; i < k ; i++){
      cin>>h[i];
    }
    solve(A, h);
    return 0;
  }

  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
  }

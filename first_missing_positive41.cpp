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

  void swap(vector<int>&vec , int i , int j){
    int t = vec[i];
    vec[i] = vec[j];
    vec[j] = t;
  }

  int segregateNumbers(vector<int>&v){

    int index = 0;
    for(int i=0 ; i < v.size(); i++){
      if(v[i] > 0){
        swap(v , index , i);
        index++;
      }
    }

    return index;
  }

  // int segregateNumbers(vector<int>&v){
  //   int low = 0 , high = v.size()-1,count=0;
  //   while(low < high){
  //       if(v[low] <= 0 && v[high] > 0){
  //           // swap
  //           swap(v , low , high);
  //           count++;
  //           low++;
  //           high--;
  //       }
  //       if(v[low] > 0){
  //         count++;
  //         low++;
  //       }
  //       if(v[high] <= 0){
  //         high--;
  //       }
  //   }
  //   cout<<count;
  //   if(low == high){
  //     return low+1;
  //   }
  //   else{
  //       return low;
  //     }
  // }

  int firstMissingPositive(vector<int>v){

      if(v.size() == 1 && v[0] <=0){
            return 1;
      }
      int index = segregateNumbers(v);

      for(int i=0 ; i <index ; i++){
        if(abs(v[i]) <= index && v[abs(v[i])-1] > 0){
          v[abs(v[i])-1] = -v[abs(v[i])-1];
        }
      }

      for(int i=0 ; i<index ; i++){
        if(v[i] > 0){
          return i+1;
        }
      }

      return index+1;
  }

  int code(){
    //code here
    vector<int>vec={-1,-2};
    cout<<firstMissingPositive(vec);
    return 0;
  }

  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
  }

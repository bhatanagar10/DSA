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

  int findDuplicate(vector<int>&vec){
      for(int i=0 ; i < vec.size() ; i++){
        if(vec[abs(vec[i])-1] < 0){
          return abs(vec[i]);
        }
        else{
          vec[vec[i]-1]=-vec[vec[i]-1];
        }
      }
      return -1;

  }

  // int findDuplicate(vector<int>& vec) {
  //       int answer=-1;
  //       for(int i=0 ; i < vec.size() ; i++){
  //           int a = abs(vec[i]);
  //       if(vec[a] < 0){
  //           answer = abs(vec[i]);
  //           break;
  //       }
  //       else{
  //         vec[a]=-vec[a];
  //       }
  //     }
  //
  //       for(auto i: vec){
  //           i = abs(i);
  //       }
  //     return answer;
  //   }

  int code(){
    //code here
    vector<int> v={1,3,4,2,2};
    cout<<findDuplicate(v);

    return 0;
  }

  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
  }

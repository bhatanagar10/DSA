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

  vector<string> solve(vector<string>keypad ,string input){
    vector<string>result,arr;
    if(input.length() == 0){
      result.push_back("");
      return result;
    }

    arr = solve(keypad ,input.substr(1,input.length()));
    int k = (int)input[0] - (int)'0';
    for(int i=0 ; i < keypad[k].length(); i++){
      for(auto j : arr){
        result.push_back(keypad[k][i] + j);
      }
    }
    return result;
  }

  int code(){
    //code here
    vector<string>keypad = {"","" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string input;
    cin>>input;
    // cout<<(int)input[0] - (int)'0';
    // cout<<input.substr(1, input.length());
    vector<string>result = solve(keypad , input);
    for(auto i: result){
      cout<<i<<" ";
    }
    return 0;
  }

  int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    code();
    return 0;
  }

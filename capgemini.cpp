/* Capgemini coding test */
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
/* Problem statement :
an integer ( Z )is considered to be good integer, on two conditions:-
1) X ^ Y = Z , where X and Y are two integers
2) X & Y =0
*/



/* Problem Statement
  Next greatest element distance
*/
vector<int> stock(vector<int>vec){

    vector<int>result(vec.size());
    stack<int>s;
    result[vec.size()-1]=0;
    s.push(vec.size()-1);

    if(vec.size() == 1){
      return result;
    }

    for(int i=vec.size()-2 ; i>=0 ;i--){
      if(s.empty()){
        result[i] = 0;
      }
      else{
        while(!s.empty() && vec[s.top()] < vec[i]){
          s.pop();
        }
        if(s.empty()){
          result[i] = 0;
        }
        else{
          result[i] = s.top() - i;
        }
        s.push(i);
      }
    }

    return result;
}

int code(){
    //code here
    vector<int>vec={1,5,4,3,6};

    vector<int>v=stock(vec);
    for(auto i: v){
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

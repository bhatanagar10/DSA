/*
Here numbers are repeating twice and there is one unique non - repeating number
using XOR we can do it

{ 1 , 2 , 3 , 2 , 1 }

1 ^ 2 ^ 3 ^ 2 ^ 1 
1 ^ 1 =0 
2 ^ 2 =0
remaining is 3
*/
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

int code(){
    //code here 
    vector<int>vec={ 1,2,3,2,1};
    int rev =vec[0];
    for(int i=1 ; i<vec.size();i++){
        rev ^= vec[i];
    }

    cout<<rev;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
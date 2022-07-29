#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>
#include<list>
#include"myFunctions.h"

using namespace std;

//count digits
int countDigit(long long n) {
  return floor(log10(n) + 1);
}

//swap elements of array or string with given indices
template <typename T> void swap(T &x , int i , int index)
{ 
    char s;
    s = x[i];
    x[i] = x[index];
    x[index] = s;
}

// convert string to int
int string_to_int(string str){
  return stoi(str);
}

// convert int to string
string int_to_string(int a){
  return to_string(a);
}
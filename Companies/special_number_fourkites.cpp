#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>
#include<math.h>
#include"../headerfiles/myFunctions.cpp"

using namespace std;
#define N 3123
#define D 5
#define S 123

void special_number(){
    int number=0, k=0;
    number = S + (k*pow(10,3));
    while(number <= N){
        cout<<number<<endl;
        k++;
        number = S + (k*pow(10,3));
    }
}

int code(){
    //code here 
    special_number();
    return 0;
}

int main(){
    code();
    return 0;
}
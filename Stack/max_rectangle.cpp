#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>
#include "largest_rectangular_area.cpp"

using namespace std;
#define N 4

bool M[N][N]=  { {0 ,1, 1, 0},
                 {1 ,1, 1, 1},
                 {1 ,1 ,1 ,1},
                 {1 ,1, 0, 0}
                };

int max_Rectangle(){
    vector<int>vec;
    vec.assign(4,0);
    int area=0;
    for(int i = 0 ; i <N ; i++){
        for(int  j= 0 ; j< N ; j++){
            if(i== N-1 && M[i][j] == 0){
                vec[j] = 0;
            }
            else{
                vec[j]+=M[i][j];
            }
        }
        int newArea = largest_rectangle_area(vec);
       if(area < newArea){
            area = newArea;
        }
        
    }
    return area;

}

int code(){
    //code here 
    
    cout<<" "<<max_Rectangle();
   
    return 0;
}

int main(){
    code();
    return 0;
}

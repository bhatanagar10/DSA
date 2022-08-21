/*
This problem was asked by Google. 
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a tile you can walk on. Each False boolean represents a wall . 
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no 
possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board. 

For example, given the following board: 

and start = (3, e) (bottom left) and end = (0 , 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) 
because there is a wall everywhere else on the second row. 

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

void print2DVector(vector<vector<int>>arr){

    for(auto i: arr){
        for(auto e:i){
            cout<<e;
        }
        cout<<endl;
    }

}

bool isSafe(pair<int,int>current , vector<vector<int>>matrix ,vector<vector<int>>&sol){
    
    if(current.first <matrix.size() && current.second < matrix[0].size() && matrix[current.first][current.second]==1 && sol[current.first][current.second]==0){
        return true;
    }
    return false;
}

void solve(pair<int,int>current , pair<int,int>end ,vector<vector<int>>matrix,vector<vector<int>>&sol, string path){
    
    if(current == end){
        sol[current.first][current.second]=1;
        cout<<"Path:-"<<path<<"\n";
        cout<<"No. of steps:-"<<path.length()<<"\n";
        print2DVector(sol);
        cout<<endl;
        sol[current.first][current.second]=0;
        return;
    }

    if(!isSafe(current , matrix ,sol))
        return;

    sol[current.first][current.second]=1;
    pair<int,int>p; 

    //right
    p=make_pair(current.first , current.second+1);
    path.push_back('R');
    solve(p, end , matrix , sol,path);
    path.pop_back();

    //up
    p=make_pair(current.first-1 , current.second);
    path.push_back('U');
    solve(p, end , matrix , sol,path);
    path.pop_back();

    //left
    p=make_pair(current.first , current.second-1);
    path.push_back('L');
    solve(p, end , matrix , sol,path);
    path.pop_back();

    //down
    p=make_pair(current.first+1 , current.second);
    path.push_back('D');
    solve(p, end , matrix , sol,path);
    path.pop_back();

    sol[current.first][current.second]=0;

    return;
}

int code(){
    //code here 
    vector<vector<int>>matrix= {
        {1 , 1 , 1 , 1},
        {0 , 0 , 1 , 0},
        {1 , 1 , 1 , 0},
        {1 , 1 , 1 , 1}
    };
    vector<vector<int>>sol(matrix.size() , vector<int>(matrix[0].size() , 0));
    pair<int,int>start=make_pair(3,0),end=make_pair(0,0);
    string path="";
    solve(start , end,matrix,sol,path);

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
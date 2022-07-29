// backtracking
#include<iostream>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;
#define N 4
void print2DVector(vector<vector<bool>>arr){

    for(auto i: arr){
        for(auto e:i){
            cout<<e;
        }
        cout<<endl;
    }
}

/* find one possible path */

/* bool isSafe(int x , int y , vector<vector<bool>>&arr ){

    if(x>=0 && x<= N-1 && y>=0 && y<= N-1 && arr[x][y] == 1 ){
        return true;
    }

    return false;
} 

bool solve(int x, int y , vector<vector<bool>>&arr , vector<vector<bool>>&sol , string &path){

    // if reached the destination
    if(x==N-1 && y== N-1){
        sol[x][y]=1;
        return true;
    }

    // check if it is bounds and track is open
    if(!isSafe(x,y,arr))
        return false;

    sol[x][y] = 1;

    //down
    if(solve(x+1 , y , arr , sol,path)){
        path='D'+path;
        return true;
    }

    //right        
    if(solve(x , y+1 , arr , sol,path)){
        path='R'+path;
        return true;
    }

    //left 
    if(solve(x , y-1 , arr , sol,path)){
        path='L'+path;
        return true;    
    }

    //up
    if(solve(x-1 , y , arr , sol,path)){
        path='U'+path;
        return true;    
    }

    sol[x][y]= 0;
    return false;    
}    */
 


/* find all possible paths */
bool isSafe(int x , int y , vector<vector<bool>>&arr , vector<vector<bool>>&sol ){

    if(x>=0 && x<= N-1 && y>=0 && y<= N-1 && arr[x][y] == 1 && sol[x][y] !=1 ){
        return true;
    }

    return false;
}

void solve(int x, int y , vector<vector<bool>>&arr , vector<vector<bool>>&sol , string path){

    // if reached the destination
    if(x==N-1 && y== N-1){
        sol[x][y]=1;
        cout<<"Path:- "<<path<<endl;
        print2DVector(sol);
        sol[x][y]=0;
        return;
    }

    // check if it is bounds and track is open
    if(!isSafe(x,y,arr,sol))
        return;

    sol[x][y] = 1;

    //down
    solve(x+1 , y , arr , sol , path+'D');

    //right        
    solve(x , y+1 , arr , sol, path+'R');
    
    //left 
    solve(x , y-1 , arr , sol, path+'L');

    //up
    solve(x-1 , y , arr , sol, path+'U');

    sol[x][y]=0;

    return;
        
}   
int code(){
    //code here 
    vector<vector<bool>>arr= { { 1, 0, 0, 0 },
                              { 1, 1, 0, 0 },
                              { 1, 1, 0, 0 },
                              { 0, 1, 1, 1 } };

    vector<vector<bool>>sol(arr.size() , vector<bool>(arr[0].size() , 0));
    string path="";
    print2DVector(arr);
    cout<<endl<<endl;
    solve(0 ,0,arr,sol,path);

    return 0;
}

int main(){
    code();
    return 0;
}
/* for optimal approach use hashmaps 
store the value in map so that searching can be done at O(1) not O(N) 
For row:- store the value with that particular row in maps
For left diagonal:- store the value with key (n-1+column-row) in map
For right diagonal:- store the value with key (column + row) in map
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;
#define n 4

void print2DVector(vector<vector<bool>>arr){

    for(auto i: arr){
        for(auto e:i){
            cout<<e;
        }
        cout<<endl;
    }
}

bool isSafe(int col , int row , vector<vector<bool>>&board){

    if(col ==0){
        // if column is first that is 0, then place it there
        return true;
    }
    else{
        // else if check for if it is feasible
        int c= col-1; int r= row;

        //check for same row
        while(c>=0){
            
            if(board[r][c] == 1){
                return false;
            }
            c--;
        }

        // check for left top diagonal
        c = col-1;
        r= row-1;
        while(c>=0 && r>=0){
            if(board[r][c]==1){
                return false;
            }
            c--;
            r--;
        }

        // check for left down diagonal
        c= col-1;
        r= row+1;
        while(c>=0 && r<n){
            if(board[r][c]==1){
                return false;
            }
            c--;
            r++;
        }

        return true;

    }
}

void solve(int col , vector<vector<bool>>&board){
    if(col ==n){
        print2DVector(board);
        cout<<endl<<endl;
        return;
    }

    for(int row =0 ; row<n ; row++){
        
        if(isSafe(col, row , board)){
            board[row][col]=1;
            solve(col+1 , board);
            board[row][col]=0;
        }
    }
    return;
}

int code(){
    //code here 
    vector<vector<bool>>board(n , vector<bool>(n , 0));

    solve(0,board);
    cout<<endl;

    return 0;
}

int main(){
    code();
    return 0;
}
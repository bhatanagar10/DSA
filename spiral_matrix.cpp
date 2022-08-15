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
void print_matrix(vector<vector<int>>vec){

    for(auto i:vec){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

vector<int> spiralMatrixI(vector<vector<int>>matrix){
    int row=matrix.size(),col=matrix[0].size();
    vector<int>arr;
    int leftS=0,leftE=col-1,topS=0,topE=row-1;

    while(leftS <= leftE && topS <= topE ){

        for(int i=leftS ; i<=leftE ;i++){
            arr.push_back(matrix[topS][i]);
        } 

        for(int i =topS+1; i<=topE-1 ; i++){
            arr.push_back(matrix[i][leftE]);
        }

        if(topS != topE){
            for(int i=leftE ; i>=leftS ;i--){
                arr.push_back(matrix[topE][i]);
            }
        }
        
        if(leftS != leftE){
            for(int i=topE-1;i>=topS+1 ;i--){
                arr.push_back(matrix[i][leftS]);
            } 
        }
        
        leftS++;
        leftE--;
        topS++;
        topE--;
    }        
    

    return arr;
}

vector<vector<int>> spiralMatrixII(int n){

    vector<vector<int>>m(n,vector<int>(n));
    
    int leftS=0,leftE=n-1,topS=0,topE=n-1, k=1;

    while(leftS <= leftE && topS <= topE ){
        for(int i=leftS ; i<=leftE ;i++){
            m[topS][i]=k;
            k++;
        } 

        for(int i =topS+1; i<=topE-1 ; i++){
            m[i][leftE]=k;
            k++;
        }

        if(topS != topE){
            for(int i=leftE ; i>=leftS ;i--){
                m[topE][i]=k;
                k++;
            }
        }
        
        if(leftS != leftE){
            for(int i=topE-1;i>=topS+1 ;i--){
                m[i][leftS]=k;
                k++;
            } 
        }
        
        leftS++;
        leftE--;
        topS++;
        topE--;
    }      
   
    return m;  
}

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    
    vector<vector<int>>vec;

    int left=cStart-1, right=cStart+1, top = rStart-1 , bottom = rStart+1;

    vector<int>temp={rStart, cStart};
    vec.push_back(temp);

    while(!(top<0 && bottom>=rows && left<0 && right>=cols)){

        //right
        if(right < cols){

            for(int i=top+1 ; i<=bottom-1;i++){
                temp={i,right};
                vec.push_back(temp);;
            }

        }

        if(right < cols && bottom < rows){
            temp={bottom , right};
            vec.push_back(temp);
        }

        //down
        if(bottom < rows){
            for(int i =right-1; i>=left+1;i--){
                temp={bottom , i};
                vec.push_back(temp); 
            }
        }

        if(left>=0 && bottom < rows){
            temp={bottom , left};
            vec.push_back(temp);
        }

        //left
        if(left >= 0){
            for(int i=bottom-1; i>=top+1 ; i--){
                temp ={i,left};
                vec.push_back(temp);
            }   
        }

        if(top >=0 && left>=0){
            temp={top , left};
            vec.push_back(temp);
        }

        //top
        if(top>=0){
            for(int i=left+1 ; i<=right-1;i++){
                temp={top , i};
                vec.push_back(temp);
             }
        }

        if(right < cols && top >=0){
            temp={top , right};
            vec.push_back(temp);
        }


        top = (top-1) <0 ? -1 : top-1;
        bottom = bottom+1 >=rows ? rows : bottom+1;
        left = left-1 <0 ? -1 : left-1;
        right = right +1 >= cols ? cols : right+1;

    }

    print_matrix(vec);
    cout<<"Size"<<vec.size();
}

int code(){
    //code here 
    vector<vector<int>>vec={{1,2,3,4}, {5,6,7,8}};
    // vector<int>arr=spiralMatrixI(vec);
    // vector<vector<int>> m = spiralMatrixII(6);
    spiralMatrixIII(5,6,1,4);
   
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
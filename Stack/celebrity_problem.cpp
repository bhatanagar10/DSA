
#include <bits/stdc++.h>
using namespace std;

#define N 4

bool MATRIX[N][N] = {{0 ,1, 1, 0} ,{0 ,0 ,0 ,1} ,{1 ,1 ,0 ,1} ,{1 ,1 ,1 ,0}};

bool knows(int A, int B)
{
    return MATRIX[A][B];
   
}

int findCelebrity(int n)
{
    if(n==0){
        return 0;
    }

    int id = findCelebrity(n-1);
    if(id == -1){
        return n;
    }
    if(knows(n,id)){
        if(!knows(id,n)){
            return id;
            
        }
        else{
            return -1;
        }
    }
    else if(knows(id,n)){
        return n;          
    }
    else{
        return -1;
    }
}

int Celebrity(int n)
{

    int celebrity = findCelebrity(n);

        for(int i = 0 ; i < n ; i++){
            if(i!=celebrity) {
                if(MATRIX[celebrity][i] !=0 || MATRIX[i][celebrity] != 1){
                    celebrity= -1;
                    break;
                }
            }
        }
    cout<<celebrity;

    return 0;
}

int main()
{   
    int n = N;
    Celebrity(n-1);
}
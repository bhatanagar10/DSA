#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j,  int R , int C)
{
	return (i >=0 && i < R && j >=0 && j < C);
}

int solve(vector<vector<char>>vec, int i, int j, int direction , int R , int C){

	if (isValid( i , j , R , C) == false || vec[i][j] == 'X')
		return 0;

    int marbleThere = ( vec[i][j] == '1') ? 1 : 0 ;

    if(direction){
        // move right
        //move one down and change direction
        return max(solve(vec , i , j+1 , 1 , R, C) , solve(vec , i+1 , j , 0 , R,C))+marbleThere;
                
    }

    else{
        // move left
        //move one down and change direction
        return max(solve(vec , i , j-1 , 0 , R , C), solve(vec , i+1 , j , 1 , R , C))+marbleThere;

    }
}

int main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<char>>vec(m , vector<char>(n));
    for(int i=0 ; i < m ; i++){
        for(int j=0 ; j< n ; j++){
            cin>>vec[i][j];
        }
    }
    cout<<endl;
    for(int i=0 ; i < m ; i++){
        for(int j=0 ; j< n ; j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<solve(vec , 0 , 0 , 1 , m , n);

	return 0;
}

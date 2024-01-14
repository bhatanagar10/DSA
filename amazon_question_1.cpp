#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

 bool cmp(pair<char, int>& a,pair<char, int>& b)
{
    return a.second > b.second;
}
void mapSort(map<char, int>M, vector<pair<char, int> > &A)
{
    
    
    for (auto& it : M) {
        A.push_back(it);
    }
  
   
    sort(A.begin(), A.end(), cmp);
    
}

int func(string text){
    map<char,int>count;
    int mincount=0;

    for(int i=0 ;i<text.length(); i++){
        count[text[i]]++;
    }
    
    if(count.size() == 9 || count.size()==1){
        for(auto x:count){
            mincount+=x.second;
        }
    }

    else{

        vector<pair<char, int> > A;
        mapSort(count, A);
        /*for(auto& it : A) {
  
         cout << it.first << ' '
             << it.second << endl;
        } 
        }*/
        int k=1;
        for(auto x:A){
            if(k<=9){
                mincount+=x.second;
            }
            else if(k>9 && k<=18){
                mincount+=x.second+1;
            }
            else{               
                mincount+=x.second+2;
            }
            
            k++;
        }
    
    }

    return mincount;

}
 
int code(){
    //code here 
//    string str="abcghdiefjoba";
    string str="qwertyuiopasdfghjklzxcvbnm";
    string s="12:00", st="";
    int i=0,num;
    while(s[i]!=':'){
        st=st+s[i];
        i++;
    }
    stringstream ss;
    ss<<st;
    ss>>num;
    if(num >=0 && num<=11){
        cout<<"AM";
    }
    else{
        cout<<"PM";
    }
    //func(str);
    return 0;
}

int main(){
    code();
    return 0;
}
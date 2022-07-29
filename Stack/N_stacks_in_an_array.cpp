/* we have to implement N stack using a single array */


/* here arr is array where elements will be stored 
 top array represents top of N stacks 
 next array will contain the index of all the previous elements of a particular stack
 freespace will tell where to find the next freespace */

/* suppose for stack 1
 goto top array for that stack and find the index for the element in that array 
 and u will find the index for upcoming element in top array 
 simultaneously that index in next array will also tell the index of upcoming element 
 */

/* for pop() operation just follow the same push() operation in reverse order */

#include<iostream>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;
#define N 10
#define Stacks 3

class NStacks{

    
    int *arr= new int[N];
    int *next= new int[N];
    vector<int>top;
    int freeSpace;

    public:

    NStacks(){
        //initialize stack
        freeSpace = 0;
        top.assign(Stacks , -1);

        //initialize next array
        for(int i = 0 ; i<N; i++){
            if(i== N-1)
                next[i] = -1;
            else{
                next[i] = i+1;   
            }
        }
        

    }

    void NStacks_push(int num , int stack){
        if(freeSpace == -1){
            cout<<"No space"<<endl;
            return;
        }
        int index= freeSpace;
        freeSpace = next[freeSpace];

        if(top[stack-1] == -1){
            next[index] = -1;
        }
        else{
            next[index] = top[stack-1];

        }
            arr[index] = num;
            top[stack-1] = index;        
    }

    void NStacks_pop(int stack){
        if(top[stack-1] == -1){
            cout<<"Stack empty"<<endl;
        }
        int index = top[stack-1];
        top[stack-1] = next[index];
        next[index] = freeSpace;
        freeSpace = index;
    }
    
    void NStacks_display(int s){
        
        if(top[s-1] == -1){
            cout<<"Stack empty"<<endl;
            return;
        }
        int index= top[s-1];
        while(index != -1){
            cout<<arr[index]<<" ";
            index= next[index];
        }
        cout<<endl;
    }
};

int code(){
    //code here 
    NStacks s;
    s.NStacks_push(10,1);
    s.NStacks_push(20,1);

    s.NStacks_push(30,2);
    s.NStacks_push(40,2);

    s.NStacks_display(1);
    s.NStacks_display(2);

    s.NStacks_pop(1);

    s.NStacks_display(1);
    

    return 0;
}

int main(){
    code();
    return 0;
}
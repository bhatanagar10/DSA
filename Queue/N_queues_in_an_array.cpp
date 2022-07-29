#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;
#define N 10
#define Queues 3

class NQueues{
    
    int *arr= new int[N];
    int *next= new int[N];
    pair<int,int>frontRear[Queues];
    int freeSpace;

    public:

    NQueues(){
        //initialize stack
        freeSpace = 0;

        //initialize front and rear
        for(int i=0; i<Queues ; i++){
            frontRear[i].first= -1;
            frontRear[i].second=  -1;
        }

        //initialize next array
        int i;
        for( i = 0 ; i<N; i++){
                next[i] = i+1;   
        }
        next[i-1]= -1;
        

    }

    void NQueues_push(int num , int queue){
        if(freeSpace == -1){
            cout<<"No space"<<endl;
            return;
        }
        int index= freeSpace;
        freeSpace = next[freeSpace];
        next[index] = -1;

        if(frontRear[queue - 1].first == -1){
            frontRear[queue-1].first= index;
            frontRear[queue-1].second= index;
            
        }
        else{
            next[frontRear[queue-1].second]=index;
            frontRear[queue-1].second= index;
            //next[index] = frontRear[queue-1].first;

        }
            arr[index] = num;
    }

    void NQueues_pop(int queue){
        if(frontRear[queue-1].first == -1){
            cout<<"Queue empty"<<endl;
        }

        int index = frontRear[queue-1].first;
        frontRear[queue-1].first = next[frontRear[queue-1].first];

        next[index] = freeSpace;
        freeSpace = index;

    }
    
    void NQueues_display(int queue){
        
        if(frontRear[queue-1].first == -1){
            cout<<"Stack empty"<<endl;
            return;
        }
        
        int index= frontRear[queue-1].first;
        while(index != -1){
            cout<<arr[index]<<" ";
            index= next[index];
        }
        cout<<endl;
    }
};

int code(){
    //code here 
    NQueues s;
    s.NQueues_push(10,1);
    s.NQueues_push(20,1);

    s.NQueues_push(30,2);
    s.NQueues_push(40,2);

    s.NQueues_display(1);
    //s.NQueues_display(2);

    s.NQueues_pop(1);

    s.NQueues_display(1);
    

    return 0;
}

int main(){
    code();
    return 0;
}
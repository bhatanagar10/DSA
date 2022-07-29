/* in this program we have to reverse first k elements of queue */

/* approach is simple using recursion we will put the first k elements at the end of queue in reverse order and then shift the remaining
at the end of queue as it is*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

void reverse_first_k_elements(queue<int>&q, int k){

    if(k == 0){
        return;
    }

    int num = q.front();
    q.pop();

    reverse_first_k_elements(q,--k);

    q.push(num);
    return;
}

void shift_queue(queue<int>&q,int k){
    while(q.size() - k > 0 ){
        int num = q.front();
        q.pop();
        q.push(num);
        k++;
    }
}

int code(){
    //code here 

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k=3;
    reverse_first_k_elements(q,k);
    shift_queue(q,k);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}

int main(){
    code();
    return 0;
}
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

uint32_t reverseBits(uint32_t n) {
        
    int k=0;
    uint32_t answer=0, input = n,mask;
    for(int i=0; i<32;i++){
        mask = 1<<i;
        input = n & mask;
        input >>=i;
        answer <<=1;
        answer = input | answer;
    }
    return answer;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    uint32_t n=3;
    cout<<reverseBits(3);
	return 0;
}

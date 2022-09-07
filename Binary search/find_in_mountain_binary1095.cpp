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

class MountainArray {
 public:
    vector<int>vec;
   int get(int index){
   	return vec[index];
   }
   int length(){
   		return vec.size();
   }
};

int findPeak(MountainArray &mountainArr){
	int low = 0,high = mountainArr.length()-1,mid;


	while(low < high){

		mid  = (low + high)/2;

		if(mountainArr.get(mid) < mountainArr.get(mid+1)){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}

	return mid;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
	int peakIndex = findPeak(mountainArr);
	int low , high , mid;

	// if peak is target
	if(mountainArr.get(peakIndex) == target){
		return peakIndex;
	}

	// for left side of peak
	low = 0;
	high = peakIndex-1;

	while(low <= high){
		mid = (low + high) /2;

		if(mountainArr.get(mid) == target){
			return mid;
		}

		else if(target > mountainArr.get(mid)){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}

	//for right side of peak
	low = peakIndex+1;
	high = mountainArr.length()-1;

	while(low <= high){
		mid = (low + high) /2;

		if(mountainArr.get(mid) == target){
			return mid;
		}

		else if(target > mountainArr.get(mid)){
			high = mid-1;
		}
		else{
			low = mid;
		}
	}

	return -1;

}

int code(){
    //code here 
    MountainArray obj;
	obj.vec={1,5,2};
	cout<<findInMountainArray(5 , obj);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    code();
    return 0;
}
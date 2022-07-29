#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

/* 
void merge(vector<int>& nums1, int m , vector<int>& nums2 , int n) {

	vector<int>temp;

	int i = 0 , j =0;
	while(i < (m-n) && j < n){
		if(nums1[i] < nums2[j]){
			temp.push_back(nums1[i++]);
		}
		else{
			temp.push_back(nums2[j++]);
		}
	}

	while(i < m-n){
		temp.push_back(nums1[i++]);
	}

	while(j < n){
		temp.push_back(nums2[j++]);
	}
	nums1.clear();
	nums1.assign(temp.begin(), temp.end());
	

}
 */

void merge(vector<int>& nums1, int m , vector<int>& nums2 , int n) {
	int x = m+n-1;
	int y = n-1;
	int z = m-1;


	while(z>= 0 && y>=0 ){
		if( nums1[z] > nums2[y] ){
			nums1[x--] = nums1[z--];
		}
		else{
			nums1[x--] = nums2[y--];
		}
	}

	while(z>=0){
		nums1[x--] = nums1[z--];
	}
	while(y>=0){
		nums1[x--] = nums2[y--];
	}
}

int code(){
	//code here 
	vector<int>nums1 = {1,2,3,0,0,0};
	vector<int>nums2 = {2,5,6};

	merge(nums1,nums1.size() - nums2.size() , nums2 , nums2.size());

	for(int i = 0 ; i < nums1.size() ; i++){
		cout<<nums1[i];
	}cout<<endl;
	for(int i = 0 ; i < nums2.size() ; i++){
		cout<<nums2[i];
	}
	return 0;
}

int main(){
	code();
	return 0;
}
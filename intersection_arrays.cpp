#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

vector<int> intersection_array(unordered_map<int,int>nums_1 ,unordered_map<int,int>nums_2){
    vector<int>result;

    for(auto e: nums_1){
                if(nums_2.find(e.first) != nums_2.end()){
                        int count = ( e.second <= nums_2[e.first]) ? e.second : nums_2[e.first];               
                        while(count >0){
                            result.push_back(e.first);
                            count--;
                        }
                }
            }

            return result;

}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nums_1,nums_2;
        vector<int>result;

        for(int i = 0 ;i< nums1.size() ; i++){
            nums_1[nums1[i]]++;
        }


        for(int i = 0 ;i< nums2.size() ; i++){
            nums_2[nums2[i]]++;
        }
    
        result = ( nums1.size() <= nums2.size() ) ? intersection_array(nums_1 , nums_2) : intersection_array(nums_2 , nums_1);
            
        
        for(auto i : nums_1){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<endl;
        for(auto i : nums_2){
            cout<<i.first<<" "<<i.second<<endl;
        }
    
        return result;

    }

int code(){
    //code here 
    vector<int>nums1 = {1,2,3,4,4};
    vector<int>nums2 = {1,2,3,4,4};
    vector<int>result = intersect(nums1,nums2);
    //cout<<result;
    return 0;
}

int main(){
    code();
    return 0;
}
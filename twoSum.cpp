#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<bits/stdc++.h>


using namespace std;

/* vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for(int i = 0 ; i < nums.size() ; i++){    
            vector<int>::iterator it = std::find ( nums.begin() + i +1, nums.end(),  target - nums[i]   );
             
                if(it != nums.end()){
                    result.push_back(i);
                    result.push_back(it - nums.begin());
                    break;
                }
	    
        }
    return result;
}  */   

/* vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int,int>mappa;
        for(int i = 0 ; i < nums.size() ; i++){    
             
                if(mappa.find(target - nums[i]) != mappa.end()){
                    result.push_back(i);
                    result.push_back(mappa[target - nums[i]]);
                    break;
                }
                    mappa.insert({ nums[i], i });
	    
        }
        unordered_map<int,int>:: iterator itr;
        for (itr = mappa.begin(); itr != mappa.end(); itr++)
    {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stores the value part
        cout << itr->first << "  " << itr->second << endl;
     }
    return result;
}   */


vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;                  
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)    
        {
            int val = target-nums[i];
            if(m.find(val)!=m.end()) 
            {
                ans.push_back(m.find(val)->second);
                ans.push_back(i);
                break;
            }
            m.insert(pair<int,int>(nums[i],i)); 
        }
        return ans;
}


int code(){
    //code here 

    vector<int>nums={ 2,5,5,6};

    vector<int>result = twoSum(nums , 10);

    for(auto i: result){
        cout<<i<<'\t';
    }

    return 0;
}

int main(){
    code();
    return 0;
}
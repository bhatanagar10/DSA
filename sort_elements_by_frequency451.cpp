/*
//	 CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Used for sorting by frequency. And if frequency is same,
// then by appearance
bool sortByVal(const pair<int, int>& a,
					const pair<int, int>& b)
{

// If frequency is same then sort by index
if (a.second == b.second)
	return a.first < b.first;

return a.second < b.second;
}

// function to sort elements by frequency
vector<int>sortByFreq(int a[], int n)
{

vector<int>res;

unordered_map<int, int> m;

vector<pair<int, int> > v;

for (int i = 0; i < n; ++i) {

	// Map m is used to keep track of count
	// of elements in array
	m[a[i]]++;
}

// Copy map to vector
copy(m.begin(), m.end(), back_inserter(v));

// Sort the element of array by frequency
sort(v.begin(), v.end(), sortByVal);

for (int i = 0; i < v.size(); ++i)
	while(v[i].second--)
	{
			res.push_back(v[i].first);
	}

return res;
}

// Driver program
int main()
{

int a[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
int n = sizeof(a) / sizeof(a[0]);
vector<int>res;
res = sortByFreq(a, n);

for(int i = 0;i < res.size(); i++)
		cout<<res[i]<<" ";

return 0;

}
*/


// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};

vector<int> frequencySort(vector<int>& arr)
{
	unordered_map<int, int> mpp;
  vector<int>answer;
  priority_queue<pair<int,int>,vector<pair<int,int>> ,  Compare> maxH;

	for (int a : arr) {
		mpp[a]++;
	}

	for (auto m : mpp) {
		maxH.push({ m.first, m.second });
	}

	while (maxH.size() > 0) {
		int val = maxH.top().first;
		int freq = maxH.top().second;

		while (freq--) {
			  answer.push_back(val);
		}
		maxH.pop();
	}

  return answer;
}

int main()
{
	vector<int> vec{1,1,2,2,2,3};

  vector<int>answer = frequencySort(vec);
  for(auto i : answer){
    cout<<i<<" ";
  }

	return 0;
}

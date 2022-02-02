#include<iostream>
#include<vector>
using namespace std;

vector<int> nums;

void Josephus(int n, int k)
{         
	vector<int>::iterator iter=nums.begin();
	for(int i = 0; i<n; i++)
	{
		for(int idx = 0; idx<k-1; idx++)
		{
			iter++;
			if(iter == nums.end())
				iter = nums.begin();
		}

		cout<<*iter;
		if(i<n-1) cout<<", ";
		nums.erase(iter);

		if(iter >= nums.end())
			iter = nums.begin();
	}
}

int main()
{
	int n,k;
	
	cin>>n>>k;
	for(int i = 0; i<n; i++)
		nums.push_back(i+1);
	cout<<"<";
	Josephus(n,k);
	cout<<">";
}
#include<iostream>
#include<algorithm>
using namespace std;

int num[10000001];

bool compare(int a, int b){
    return a>b;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	
	for(int i = 0; i<n; i++)
		cin>>num[i];
	
	sort(num,num+n,compare);
	
	for(int i = 0; i<n; i++)
		cout<<num[i]<<"\n";
}
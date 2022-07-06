#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;


int main() {
  ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

  cin>>n;
  int a; cin>>a; cout<<a<<"\n"; n--;
  maxHeap.push(a);
  
  while(n--){
    cin>>a;
    if(maxHeap.size()>minHeap.size())
      minHeap.push(a);
    else if(maxHeap.size()<=minHeap.size())
      maxHeap.push(a);

    if(!minHeap.empty() && maxHeap.top()>minHeap.top()){
      int tmp1 = maxHeap.top();
      int tmp2 = minHeap.top();
      minHeap.pop(); minHeap.push(tmp1);
      maxHeap.pop(); maxHeap.push(tmp2); 
    }
    
    cout<<maxHeap.top()<<"\n";
  }
}

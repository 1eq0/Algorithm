#include<bits/stdc++.h>
using namespace std;

string N;
int M,K;
queue<string> q;

string swap_c(string s,int i, int j){
  string ret = s;
  char c1 = ret[i];
  char c2 = ret[j];
  ret[i] = c2;
  ret[j] = c1;
  return ret;
}

string bfs(string s){
  q.push(s);
  for(int k=1; k<=K; k++){
    int qsize = q.size();
    if(!qsize) break;
    set<string> visited;
    for(int qq = 0; qq<qsize; qq++)
    {
      string tmp = q.front();
      q.pop();
      for(int i = 0; i<M-1; i++){
        for(int j = i+1; j<M; j++){
          if(i==0 && tmp[j]=='0') continue;
          string swapped = swap_c(tmp,i,j);
          if(!visited.count(swapped)){
            q.push(swapped);
            visited.insert(swapped);
          }
        }
      }
    }
  }
  string ans = "0";
  while(!q.empty()){
    ans = max(ans,q.front());
    q.pop();
  }
  if(ans[0]=='0') return "-1";
  else return ans;
}

int main(){
  cin>>N>>K;
  M = N.size();

  cout<<bfs(N);
  
}

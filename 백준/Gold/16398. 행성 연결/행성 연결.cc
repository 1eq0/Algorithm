#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1001
int N;
int arr[MAXN][MAXN];
int par[MAXN];
struct node {
	int u, v, w;
	bool operator < (const node& a)const {
		return w < a.w;
	}
};
vector<node> adj;
int Find(int x) {
	if (par[x] == -1) return x;
	return par[x] = Find(par[x]);
}
bool Merge(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v) return false;
	par[u] = v;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof(par));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (i < j) {
				adj.push_back({ i,j,arr[i][j] });
			}
		}
	}
	sort(adj.begin(), adj.end());
	long long ans = 0;
	for (int i = 0; i < adj.size(); i++) {
		if (Merge(adj[i].u, adj[i].v)) ans += (long long)adj[i].w;
	}
	cout << ans << "\n";
	return 0;
}
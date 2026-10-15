/*
Need a little observation to make the algorithm effective
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, idx;
string milk;
vector<int> comp;
vector<vector<int>> adj;

void dfs(int now, int par){
    comp[now] = idx;
    for(auto next : adj[now]){
        if(next == par) continue;
        if(milk[now-1] != milk[next-1]) continue;
        dfs(next, now);
    }
}

signed main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin>>n>>m>>milk;
    comp.resize(n+1); adj.resize(n+1);
    for(int i = 1; i <= n-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    idx = 1;
    for(int i = 1; i <= n; i++){
        if(comp[i] != 0) continue;
        dfs(i, 0);
        idx++;
    }
    for(int i = 1; i <= m; i++){
        int a, b; char like; cin>>a>>b>>like;
        if(comp[a] == comp[b]){
            cout<<(milk[a-1] == like);
        }else cout<<1;
    }
}

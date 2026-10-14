#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> subordinates;

int dfs(int now, int parent){
    subordinates[now] = 0;
    for(auto next : adj[now]){
        if(next == parent) continue;
        subordinates[now] += dfs(next, now);
    }
    return subordinates[now] + 1; // anak buah + diri sendiri
}

signed main(){
    int n; cin>>n;
    adj.resize(n+1);
    subordinates.resize(n+1);
    
    for(int i = 1; i <= n-1; i++){
        int dboss; cin>>dboss;
        adj[dboss].push_back(i+1);
    }

    for(auto next : adj[1]){
        subordinates[1] += dfs(next, 1);
    }

    for(int i = 1; i <= n; i++) cout<<subordinates[i]<<" ";
}

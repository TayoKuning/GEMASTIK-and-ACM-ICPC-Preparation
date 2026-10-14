#include<bits/stdc++.h>
using namespace std;
int n, q, v, k;
vector<vector<pair<int,int>>> adj;

int dfs(int now, int parent){
    int tot = 0;
    for(auto [next, con] : adj[now]){
        if(con < k) continue;
        if(next == parent) continue;
        tot += dfs(next, now);
    }

    return tot + 1;
}

signed main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin>>n>>q;
    adj.resize(n+1);

    for(int i = 1; i <= n-1; i++){
        int x, y, z; cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    while(q--){ 
        cin>>k>>v;
        int tot = 0;
        for(auto [next, con] : adj[v]){
            if(con < k) continue;
            tot += dfs(next, v);
        }
        cout<<tot<<endl;
    }

}

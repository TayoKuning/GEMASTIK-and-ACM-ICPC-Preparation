#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, ans; 
vector<vector<int>> adj;
vector<int> sides;

int dfs(int now, int par, int length){
    vector<int> barisan; 
    barisan.push_back(0);
    barisan.push_back(0);
    for(auto next : adj[now]){
        if(next == par) continue;
        barisan.push_back(dfs(next, now, 1));
    }
    sort(barisan.begin(), barisan.end());
    int sz = barisan.size();
    ans = max(ans, barisan[sz-1] + barisan[sz-2]);
    return length + barisan[sz-1];
}

signed main(){
    cin>>n;
    adj.resize(n+1);
    sides.resize(n+1);

    int maks = 0, idxmaks = 0;
    for(int i = 1; i <= n-1; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        sides[x]++; sides[y]++;
        if(sides[x] > maks){
            maks = sides[x]; idxmaks = x;
        }else if(sides[y] > maks){
            maks = sides[y]; idxmaks = y;
        }
    }

    vector<int> barisan; 
    barisan.push_back(0);
    barisan.push_back(0);
    for(auto next : adj[idxmaks]){
        barisan.push_back(dfs(next, idxmaks, 1));
    }   
    sort(barisan.begin(),barisan.end());
    int sz = barisan.size();
    ans = max(ans, barisan[sz-1] + barisan[sz-]);
    cout<<ans<<endl;
}

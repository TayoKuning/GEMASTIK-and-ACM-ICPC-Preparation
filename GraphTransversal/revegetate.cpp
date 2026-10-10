/*
Solution is to dfs both same and different pair, and count the connected components
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> same, diff;
vector<int> color;
vector<bool> vis;
bool tv;

void add(int x, int y, char type){
    if(type == 'S'){
        same[x].push_back(y);
        same[y].push_back(x);
    }else{
        diff[x].push_back(y);
        diff[y].push_back(x);
    }
}

void dfs(int now, int col){
    vis[now] = true; color[now] = col;
    for(auto next : same[now]){
        if(vis[next]){
            if(color[next] != col){
                tv = true;
                return;
            }
            continue;
        }
        dfs(next, col);
    }

    for(auto next : diff[now]){
        if(vis[next]){
            if(color[next] == col){
                tv = true;
                return;
            }
            continue;
        }
        dfs(next, (col % 2)+1);
    }
    if(tv) return;
}

signed main(){
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    int n, m; cin>>n>>m;
    same.resize(n+1), diff.resize(n+1);
    color.resize(n+1), vis.resize(n+1);
    
    for(int i = 1; i <= m; i++){
        int x, y; char type; cin>>type>>x>>y;
        add(x,y, type);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        cnt++;
        dfs(i, 1);
        if(tv){
            cout<<"0"<<endl;
            return 0;
        }
    }

    cout<<"1";
    for(int i = 1; i <= cnt; i++) cout<<"0";
}

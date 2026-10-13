#include<bits/stdc++.h>
using namespace std;
int n, m, startx, starty; 
int grid[507][507];
int waypoint[507][507];
bool vis[507][507];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int nowx, int nowy, int limit){
    vis[nowy][nowx] = true;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int nextx = nowx + dx[i], nexty = nowy + dy[i];
            if(nextx > m || nextx < 1) continue;
            if(nexty > n || nexty < 1) continue;
            if(vis[nexty][nextx]) continue;
            int dif = abs(grid[nexty][nextx] - grid[nowy][nowx]);
            if(dif > limit) continue;
            dfs(nextx, nexty, limit);
        }
    }
}

bool valid(int d){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            vis[i][j] = false;
        }
    }

    dfs(startx, starty, d);

    for(int i = 1; i <= n; i++){
        for(int j  = 1; j <= m; j++){
            if(waypoint[i][j] == 1){
                if(!vis[i][j]) return false;
            }
        }
    }
    return true;
}


signed main(){
    freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin>>grid[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>waypoint[i][j];
            if(waypoint[i][j] == 1){
                startx = j, starty = i;
            }
        }
    }
    int l = 0, r = 1e9 + 7;
    int ans = 1e9+7;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    cout<<ans<<endl;
}

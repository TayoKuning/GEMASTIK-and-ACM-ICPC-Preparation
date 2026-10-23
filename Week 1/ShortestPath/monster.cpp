#include<bits/stdc++.h>
using namespace std;
int n, m, sy, sx;
const int maxval = 1007;
char grid[maxval][maxval];
int monster_dist[maxval][maxval], dist[maxval][maxval];
pair<int,int> parent[maxval][maxval];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,-1,1,0,0};
queue<pair<int,int>> BFS;

bool inside(int curry, int currx){
    return (curry <= n && curry >= 1 && currx <= m && currx >= 1 && grid[curry][currx] != '#');
}

void monsBFS(){
    while(!BFS.empty()){
        auto [curry, currx] = BFS.front(); BFS.pop();
        for(int i = 1; i <= 4; i++){
            int nexty = curry + dy[i], nextx = currx + dx[i];
            if(!inside(nexty, nextx)) continue;
            if(monster_dist[nexty][nextx] != -1) continue;
            monster_dist[nexty][nextx] = 1 + monster_dist[curry][currx];
            BFS.push({nexty, nextx});
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        cin>>grid[i][j];
        monster_dist[i][j] = -1, dist[i][j] = -1;
        if(grid[i][j] == 'A'){sy = i, sx = j;}
        if(grid[i][j] == 'M'){ 
            BFS.push({i,j});
            monster_dist[i][j] = 0;
        }
    }
    monsBFS();
    BFS.push({sy,sx}); dist[sy][sx] = 0;
    while(!BFS.empty()){
        auto [curry, currx] = BFS.front(); BFS.pop();
        if((curry == 1 || curry == n) || (currx == 1 || currx == m)){
            cout<<"YES"<<endl;
            cout<<dist[curry][currx]<<endl;
            vector<char> langkah;
            while(curry != sy || currx != sx){
                auto [befy, befx] = parent[curry][currx];
                if(curry - befy == 1) langkah.push_back('D');
                if(curry - befy == -1) langkah.push_back('U');
                if(currx - befx == 1) langkah.push_back('R');
                if(currx - befx == -1) langkah.push_back('L');
                curry = befy, currx = befx;
            }
            reverse(langkah.begin(), langkah.end());
            for(auto step : langkah) cout<<step;
            return 0;
        }
        for(int i = 1; i <= 4; i++){
            int nexty = curry + dy[i], nextx = currx + dx[i];
            if(!inside(nexty, nextx)) continue;
            if(dist[nexty][nextx] != -1) continue;
            if(monster_dist[nexty][nextx] != -1) if(dist[curry][currx] + 1 >= monster_dist[nexty][nextx]) continue;
            dist[nexty][nextx] = dist[curry][currx] + 1;
            parent[nexty][nextx] = {curry, currx};
            BFS.push({nexty,nextx});
        }
    }
    cout<<"NO"<<endl;
    

}

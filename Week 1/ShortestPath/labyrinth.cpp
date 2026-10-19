#include<bits/stdc++.h>
using namespace std;
const int max_value = 1007;
char grid[max_value][max_value];
int dist[max_value][max_value];
bool vis[max_value][max_value];
pair<int,int> par[max_value][max_value];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
int n, m; 

bool inside(int x, int y){
    return (x <= n && x >= 1 && y <= m && y >= 1 && grid[x][y] != '#');
}

signed main(){
    cin>>n>>m;
    int stx, sty, edx, edy;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dist[i][j] = -1;
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                stx = j, sty = i;
            }else if(grid[i][j] == 'B'){
                edx = j, edy = i;
            }
        }
    }
    queue<pair<int,int>> pos;
    pos.push({sty, stx}); dist[sty][stx] = 0;
    while(!pos.empty()){
        auto [curry, currx] = pos.front(); pos.pop();
        for(int i = 1; i <= 4; i++){
            int nexty = curry + dy[i], nextx = currx + dx[i];
            if(inside(nexty,nextx) && dist[nexty][nextx] == -1){
                vis[nexty][nextx] = true;
                dist[nexty][nextx] = dist[curry][currx] + 1;
                par[nexty][nextx] = {curry, currx};
                pos.push({nexty, nextx});
            }
        }
    }

    if(dist[edy][edx] == -1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<dist[edy][edx]<<endl;
        int curry = edy, currx = edx;
        vector<char> steps;
        while(curry != sty || currx != stx){
            auto [befy,befx] = par[curry][currx];
            if(curry - befy == 1) steps.push_back('D');
            if(currx - befx == 1) steps.push_back('R');
            if(curry - befy == -1) steps.push_back('U');
            if(currx - befx == -1) steps.push_back('L');
            curry = befy, currx = befx;
        }
        for(int i = dist[edy][edx] - 1; i >= 0; i--) cout<<steps[i];
    }
}

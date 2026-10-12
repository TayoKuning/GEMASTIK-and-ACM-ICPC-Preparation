#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
char grid[1007][1007];
bool vis[1007][1007];
int stepx[4] = {0,0,1,-1};
int stepy[4] = {1, -1, 0, 0};
int tarea, tperi;

void dfs(int cury, int curx){
    vis[cury][curx] = true;
    tarea++;
    for(int i = 0; i < 4; i++){
        int nexty = cury + stepy[i], nextx = curx + stepx[i];
        if(nexty <= n && nexty >= 1 && nextx <= n && nextx >= 1){
            if(grid[nexty][nextx] == '.'){
                tperi++;
            }else{
                if(!vis[nexty][nextx]){
                    dfs(nexty, nextx);
                }
            }
        }else tperi++;
    }
};

signed main(){
    freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
    cin>>n;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++) cin>>grid[i][j];
    }

    int mxarea = 0, mnperi = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(vis[i][j] || grid[i][j] == '.') continue;
            tarea = 0, tperi = 0;
            dfs(i,j);
            if(mxarea < tarea){
                mxarea = tarea;
                mnperi = tperi;
            }else if(mxarea == tarea) mnperi = min(mnperi, tperi);
        }
    }

    cout<<mxarea<<" "<<mnperi<<endl;
}

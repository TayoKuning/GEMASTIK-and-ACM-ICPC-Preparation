#include<bits/stdc++.h>
using namespace std;
bool pos[101][101];
bool vis[101][101];
int n, k, r, cnt;
bool road1_road2[101][101][101][101];
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};

void floodfill(int nowy, int nowx){
    vis[nowy][nowx] = true;

    for(int i = 1; i <= 4; i++){
        int nexty = nowy + dy[i], nextx = nowx + dx[i];
        if(nexty < 1 || nexty > n) continue;
        if(nextx < 1 || nextx > n) continue;
        if(road1_road2[nowy][nowx][nexty][nextx]) continue;
        if(vis[nexty][nextx]) continue;
        cnt += pos[nexty][nextx];
        floodfill(nexty, nextx);
    }
}

signed main(){
    freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
    cin>>n>>k>>r;
    for(int i = 1; i <= r; i++){
        int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;
        road1_road2[r1][c1][r2][c2] = true;
        road1_road2[r2][c2][r1][c1] = true;
    }

    for(int i = 1; i <= k; i++){
        int r1, c1; cin>>r1>>c1;
        pos[r1][c1] = 1;
    }
    vector<int> cnt_cc; cnt_cc.push_back(0);
    for(int r1 = 1; r1 <= n; r1++){
        for(int c1 = 1; c1 <= n; c1++){
            if(vis[r1][c1]) continue;
            cnt = pos[r1][c1];
            floodfill(r1, c1);
            cnt_cc.push_back(cnt);
        }
    }

    // for(auto x : cnt_cc) cout<<x<<" ";
    int ans = 0, bef = 0;
    for(int i = 1; i < cnt_cc.size(); i++){
        ans += cnt_cc[i] * bef;
        bef += cnt_cc[i];
    }
    cout<<ans<<endl;
}

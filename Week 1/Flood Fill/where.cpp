#include <bits/stdc++.h>
using namespace std;

int n; 
char grid[21][21];
bool vis[21][21];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct PCL {
    int y1, x1, y2, x2;
};

bool is_inside(PCL candidate, PCL target) {
    return (candidate.y1 >= target.y1 && candidate.x1 >= target.x1 && candidate.y2 <= target.y2 && candidate.x2 <= target.x2);
}

void floodfill(int nowy, int nowx, PCL limit, char nowchar) {
    vis[nowy][nowx] = true;

    for(int i = 0; i < 4; i++) {
        int nexty = nowy + dy[i];
        int nextx = nowx + dx[i];

        if(nexty < limit.y1 || nexty > limit.y2) continue;
        if(nextx < limit.x1 || nextx > limit.x2) continue;
        if(vis[nexty][nextx]) continue;
        if(grid[nexty][nextx] != nowchar) continue;

        floodfill(nexty, nextx, limit, nowchar);
    }
}

bool check(int y1, int x1, int y2, int x2) {
    PCL limit = {y1, x1, y2, x2};
    map<char, int> region_count;

    for(int i = y1; i <= y2; i++) {
        for(int j = x1; j <= x2; j++) {
            if(!vis[i][j]) {
                region_count[grid[i][j]]++;
                floodfill(i, j, limit, grid[i][j]);
            }
        }
    }

    for(int i = y1; i <= y2; i++) {
        for(int j = x1; j <= x2; j++) vis[i][j] = false;
    }

    if(region_count.size() != 2) return false;

    auto it = region_count.begin();
    int cnt1 = it->second;
    it++;
    int cnt2 = it->second;

    return (cnt1 == 1 && cnt2 >= 2) || (cnt1 >= 2 && cnt2 == 1);
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin>>grid[i][j];
    }

    vector<PCL> approved;
    for(int y1 = 1; y1 <= n; y1++) {
        for(int x1 = 1; x1 <= n; x1++) {
            for(int y2 = y1; y2 <= n; y2++) {
                for(int x2 = x1; x2 <= n; x2++) {
                    if(check(y1, x1, y2, x2)) {
                        approved.push_back({y1, x1, y2, x2});
                    }
                }
            }
        }
    }

    int valid_PCL = 0;
    for(size_t i = 0; i < approved.size(); i++) {
        bool maximal = true;
        for(size_t j = 0; j < approved.size(); j++) {
            if(i == j) continue;
            if(is_inside(approved[i], approved[j])) {
                maximal = false;
                break;
            }
        }
        if(maximal) valid_PCL++;
    }

    cout <<valid_PCL<<endl;
}

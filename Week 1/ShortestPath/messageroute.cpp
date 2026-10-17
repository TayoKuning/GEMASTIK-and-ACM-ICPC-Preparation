/*
Try to retrieve back the BFS knowledge (tbh this algorithm still not stick enough in my head)
*/
#include<bits/stdc++.h>
using namespace std;    

signed main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1, -1); dist[1] = 0;
    vector<bool> vis(n+1, false); vis[1] = false;
    queue<int> BFS; 

    for(int i = 1; i <= m; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS.push(1);
    while(!BFS.empty()){
        int curr = BFS.front(); BFS.pop();
        vis[curr] = true;
        for(auto next : adj[curr]){
            if(vis[next]){
                dist[curr] = min(dist[next] + 1, dist[curr]);
                continue;
            }
            dist[next] = dist[curr] + 1;
            BFS.push(next);
        }
    }
    if(dist[n] == -1) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> barisan;
        int size = dist[n] - 1, st = n;
        barisan.push_back(n);
        while(size >= 0){
            for(auto next : adj[st]){
                if(dist[next] == size){
                    st = next; break;
                }
            }
            barisan.push_back(st); size--;
        }

        cout<<barisan.size()<<endl;
        for(int i = barisan.size() - 1; i >= 0; i--){
            cout<<barisan[i]<<" ";
        }cout<<endl;
    }
}

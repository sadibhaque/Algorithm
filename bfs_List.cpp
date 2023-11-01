#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll MAX = 1e5+10;
vector <ll> graph[MAX];
ll visited[MAX];
ll level[MAX];

void bfs(ll root){
    queue <ll> q;
    q.push(root);
    visited[root] = 1;

    while(!q.empty()){
        ll current = q.front();
        q.pop();

        cout<<current<<" ";

        for(auto child : graph[current]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1;
                level[child] = level[current]+1;
            }
        }
    }
}


void addEdge(int x, int y){
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void solve() {

    ll n; cin>>n;
    for (int i = 0; i < n; i++){
        ll x,y;
        cin>>x>>y;
        addEdge(x,y);
    }

    bfs(1);

    cout<<endl;

    for (int i = 1; i <= n; i++){
        cout<<i<<" : "<<"Level : "<<level[i]<<endl;
    }

}

int main() {

    solve();

    return 0;
}

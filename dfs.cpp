#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll SIZE = 1e5+10;
vector<ll> graph[SIZE];
ll visited[SIZE];

void addEdge(ll v1, ll v2){
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

void DFS(ll target){
    cout<<target<<" ";
    visited[target] = true;

    for(auto child : graph[target]){
        if(visited[child]) continue;
        DFS(child);
    }
}

void solve() {

    ll target = 1;
    // cin>>target;

    ll ver,edge;
    cin>>ver>>edge;

    for (int i = 0; i < edge; i++){
        ll v1,v2;
        cin>>v1>>v2;

        addEdge(v1,v2);
    }

    DFS(target);

}

int main() {

    solve();

    return 0;
}



//input


// 6
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6


//ans

//1 3 5 6 2 4

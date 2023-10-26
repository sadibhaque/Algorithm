#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll SIZE =  1e5+10;
vector < ll > graph[SIZE];
bool visited[SIZE];



bool isCycle(ll vertex, ll parent){

    visited[vertex] = true;

    bool ans = false;
        for(auto child : graph[vertex]){
        if (visited[child] && child != parent) return true;
        if (!visited[child]) ans |= isCycle(child, vertex);
    }
    return ans;
}



void addEdge(ll v1, ll v2){
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}


void solve() { 

    ll ver,edge;
    cin>>ver>>edge;

    for (int i = 0; i < edge; i++){
        ll v1,v2;
        cin>>v1>>v2;

        addEdge(v1,v2);
    }

    bool ans = false;
    for (int i = 1; i <= ver; i++){ 
        if(!visited[i] && isCycle(i,-1)){
            ans = true;
            break;
        }
    }

    if(ans) cout<<"Yes\n";
    else cout<<"No\n";

}

int main() {

    solve();

    return 0;
}


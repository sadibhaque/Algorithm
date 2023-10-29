#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll SIZE = 10000;
bool graph[SIZE][SIZE];
bool visited[SIZE];

void dfs(ll start, ll ver){
    cout<<start<<" ";

    visited[start] = true;

    for (int i = 1; i <= ver; i++){
        if(graph[start][i] && !visited[i] )dfs(i,ver);  
    }
}

void addEdge(ll v1, ll v2) {
    graph[v1][v2] = true;
    graph[v2][v1] = true;
}

void solve() {

    ll ver,edg;
    cin>>ver>>edg;

    for (int i = 0; i < edg; i++){  
        ll v1,v2;
        cin>>v1>>v2;

        addEdge(v1,v2);
    }

    dfs(1,ver);

}

int main() {

    solve();

    return 0;
}


//input 

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

//output

//1 3 2 6 4 5 

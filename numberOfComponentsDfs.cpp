// Number of components for undirected graph

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double


const ll SIZE = 1e5+10;
vector <ll> graph[SIZE];
vector<vector<ll>> cont;
vector<ll>cc;
bool visited[SIZE];


void dfs(ll target_ver){

    // cout<<target_ver<<" ";
    visited[target_ver] = true;
    cc.push_back(target_ver);

    for(int child : graph[target_ver]){

        if(visited[child]) continue;

        dfs(child);

    }
}

void addEdge(ll v1, ll v2){

    graph[v1].push_back(v2);
    graph[v2].push_back(v1);

}

void solve() {

    // ll edg = 6; 

    // addEdge(0, 2);
    // addEdge(1, 2);
    // addEdge(0, 1);
    // addEdge(2, 0);
    // addEdge(2, 3);
    // addEdge(3, 3);

    // dfs(2);


    //input


    ll ver,edg;
    cin>>ver>>edg;

    for (int i = 0; i < edg; i++){
        ll v1,v2;
        cin>>v1>>v2;
        addEdge(v1,v2);
    }

    ll ctr = 0;
    for (int i = 1; i <= ver; i++){

        if(visited[i]) continue;
        cc.clear();
        dfs(i);
        cont.push_back(cc);
        ctr++;
    }

    cout<<"Number of connected components : "<<cont.size()<<" :"<<endl;
    for(auto cc : cont){
        for(auto j : cc){
            cout<<j<<" ";
        }
        cout<<endl;
    }

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

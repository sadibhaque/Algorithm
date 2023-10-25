#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll SIZE =  1e5+10;
vector < ll > graph[SIZE];
bool V[SIZE];

vector<vector<ll>> comps;
vector<ll> temp;

void DFS(ll target){
    // cout<<target<<" ";
    V[target] = true;

    temp.push_back(target);

    for(auto child : graph[target]){
        if(!V[child]) {
            
            DFS(child);
        }
    }
}

void addEdge(ll v1, ll v2){
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
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

    // DFS(target);

    ll ctr = 0;

    for (int i = 1; i <= ver; i++){
        if(V[i]) continue;
        temp.clear();
        DFS(i);
        comps.push_back(temp);
        ctr++;
    }
    cout<<ctr<<endl;

    for (auto temp : comps){
        for (auto ver : temp){
            cout<<ver<<" ";
        }
        cout<<endl;
    }

}

int main() {

    solve();

    return 0;
}


//input

// 8 5
// 1 2
// 2 3
// 2 4 
// 3 5
// 6 7

//output

// 3
// 1 2 3 5 4
// 6 7
// 8

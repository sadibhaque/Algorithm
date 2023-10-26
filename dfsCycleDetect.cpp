#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll SIZE =  1e5+10;
vector < ll > graph[SIZE];
bool visited[SIZE] = {false};



bool isCycle(ll ver, ll parent){

    visited[ver] = true;

    bool ans = false;
    for(auto child : graph[ver]){
        if(visited[child] && child == parent) continue;
        if(visited[child]) return true;

        ans |= isCycle(child,parent);
        
    }

    return ans;
}



void addEdge(ll v1, ll v2){
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}


void solve() {

    addEdge(1, 0);     
    addEdge(0, 2);
    addEdge(2, 1);   
    addEdge(0, 3);
    addEdge(3, 4); //cycle exist

    addEdge(0, 1);    
    addEdge(1, 2); // do not exist 

    ll parent = 1;

    if(isCycle(parent,parent)) cout<<"There is a cycle !"<<endl;
    else cout<<"No cycle"<<endl;

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


//There is a cycle !

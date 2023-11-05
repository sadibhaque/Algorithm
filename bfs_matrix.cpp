#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

const ll MAX = 10000;
ll graph[MAX][MAX];
ll level[MAX]; 
bool visited[MAX];

void bfs(ll root, ll ver) {
    queue<ll> q;
    q.push(root);

    while (!q.empty()) {
        ll cv = q.front();
        q.pop();

        cout<<cv<<" ";

        for (int i = 1; i <= ver; i++) {
            if (graph[cv][i] == 1 && !visited[i] && level[i] == -1) {
                q.push(i);
                visited[i] = true;
                level[i] = level[cv] + 1;
            }
        }
    }
}

void solve() {
    ll edge, ver;
    cin >> edge >> ver;
    ll root = 1;

    for (int i = 1; i <= ver; i++) {
        level[i] = -1;
    }

    for (int i = 0; i < edge; i++) {
        ll v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    level[root] = 0;

    bfs(root, ver);

    cout<<endl;

    for (int i = 1; i <= ver; i++) {
        cout << i << " - " << level[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}

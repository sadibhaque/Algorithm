#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf float


llf knapsack(pair<vector<llf>,vector<llf>> wp, llf cap, int n){

    pair<llf,int> ratio_i[n];

    for (int i = 0; i < n; i++) {
        ratio_i[i].first = wp.second[i] / wp.first[i];
        ratio_i[i].second = i;
    }

    sort(ratio_i , ratio_i + n, greater<pair<llf,ll>>());

    llf cw = 0.0;
    llf ans = 0.0;
    for (int i = 0; i < n; i++) {
        ll itemIndex = ratio_i[i].second;
        if ((cw + wp.first[itemIndex]) <= cap) {
            ans += wp.second[itemIndex];
            cw += wp.first[itemIndex];
        } else {
            ans += ratio_i[i].first * (cap - cw);
            break;
        }
    }

    return ans;
}

void solve() {

    ll cap = 20;

    pair<vector<llf>,vector<llf>> wp;// pair for weight and profit

    wp.first = {5,6,7,5}; //weight
    wp.second = {15, 10, 9, 20}; //profit

    ll n = wp.first.size();

    printf("%0.10lf\n",knapsack(wp,cap,n));
}

int main() {

    solve();

    return 0;
}

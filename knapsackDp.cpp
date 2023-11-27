#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double
#define xtr string

ll INF = 1e9+10;
ll MAX = INT_MAX;
ll G_MAX = 1e5+10;
ll MIN = INT_MIN;


ll knapsack(vector <ll> w, vector<ll> v,  ll cap, ll n){
    
    vector<vector<ll>> dp (n + 1, vector<ll>(cap + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= cap; ++j) {
            if (w[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }

    return dp[n][cap];
}




int main(){
	
	ll n,cap;
	
	cin>>n;
	cin>>cap;
	
	vector <ll> w;
	vector <ll> p;
	
	w.resize(n);
	p.resize(n);
	
	for(int i = 0; i < n; i++) cin>>w[i];
	for(int i = 0; i < n; i++) cin>>p[i];
	
	ll ans = knapsack(w,p,cap,n);
	
	cout<<ans<<endl;
	
	return 0;
}

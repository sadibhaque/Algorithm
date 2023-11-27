#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll knapsack(vector<ll>& w, vector<ll>& v, ll cap, ll n){

    vector<ll> dpc(cap + 1, 0);
    vector<ll> dpp(cap + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= cap; ++j) {
            if (w[i - 1] > j) {
                dpc[j] = dpp[j];
            } else {
                dpc[j] = max(dpp[j], dpp[j - w[i - 1]] + v[i - 1]);
            }
        }
        dpp = dpc;
    }

    return dpc[cap];
}

int main(){
	
	ll n,cap;
	
	cin>>n>>cap;
	
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


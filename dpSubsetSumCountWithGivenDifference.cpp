/* Each conquered bug is a step towards mastery. */

#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef long double ld;

typedef pair<int,int> pi;
typedef pair<string,int> ps;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ps> vps;

#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define pend cout<<"\n"
#define pctr cout<<ctr<<"\n";
#define psum cout<<sum<<"\n";
#define pans cout<<ans<<"\n";
#define ptmp cout<<tmp<<"\n";

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ins insert
#define sadib main

#define sortv(x) sort((x).begin(),(x).end())
#define sorta(x,n) sort((x),(x)+(n))
#define revv(x) reverse((x).begin(),(x).end())
#define reva(x,n) reverse((x),(x)+(n))
#define all(x) (x).begin(),(x).end()

vector<vector<int>> dp;

int generate(vector<int> arr, int n, int sum){
    if(n == 0){
        if(sum == 0){
            return 1;
        }
        else return 0;
    }

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }

    if(arr[n-1] <= sum){
        return dp[n][sum] = generate(arr,n-1,sum - arr[n-1]) + generate(arr,n-1,sum);
    }
    else return dp[n][sum] = generate(arr,n-1,sum);
}

void solve(){
    int n;
    cin>>n;

    vi arr(n);
    int tsum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        tsum += arr[i];
    }

    int dif;
    cin>>dif;

    int sum = (tsum + dif)/2;

    dp.resize(n + 1, vector<int>(sum + 1,-1));

    int ans = generate(arr,n,sum);

    pans;
}

int sadib(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

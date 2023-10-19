#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll greedyCoinMin(ll coin[], ll n, ll amount){
    ll r = amount,ans = 0;
    for (int i = n-1; i >= 0; i--){
        ans += r/coin[i];
        r %= coin[i];
        if(r == 0) break;
    }
    return ans;
}


int main()
{
    ll coin[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    ll n = sizeof(coin) / sizeof(coin[0]);
    sort(coin, coin+n);
    ll amount = 93;
    cout << greedyCoinMin(coin, n, amount);
    return 0;
}

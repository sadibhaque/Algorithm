#include <bits/stdc++.h>
using namespace std;

#define ll long long int

double greedyKnapsack(ll w[], ll p[], ll c, ll n){
    double ratio[n];

    for (int i = 0; i < n; i++) ratio[i] = (double) p[i]/w[i];

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1; j++){
            if(ratio[j] < ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(w[j],w[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }


    int temp = 0;
    double ans = 0.0;
    for (int i = 0; i < n; i++){
        if((temp + w[i]) <= c){
            ans += p[i];
            temp += w[i];
        }else{
            ans += ratio[i] * (c-temp);
        }
    }

    return ans;
}


int main()
{

    ll w[] = {3, 3, 2, 5, 1};
    ll p[] = {10, 15, 10, 12, 8};
    ll c = 10;
    ll n = sizeof(p) / sizeof(p[0]);

    cout << greedyKnapsack(w, p, c, n) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define llf double

int main()
{
    ll w[7] = {1,3,5,4,1,3,2};
    ll p[7] = {5,10,15,7,8,9,4};
    ll cap = 15;

    llf pw[7];


    for (int i = 0; i < 7; i++){
        pw[i] = (double)p[i] / w[i];
    }

    for (int i = 0; i < 7-1; i++){
        for (int j = i+1; j < 7; j++){
            if(pw[i]<pw[j]){
                swap(pw[i],pw[j]);
                swap(w[i],w[j]);
                swap(p[i],p[j]);
            }
        }
    }

    llf profit = 0.0;

    for (int i = 0; i < 7; i++){
        if(cap>0){
            int rem = min(cap,w[i]);
            profit += (rem * pw[i]);
            cap -= rem;
        }
    }

    cout<<profit<<endl;

}
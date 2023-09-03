#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[],int key,int n,int low,int high){
    while(low < high){
        int mid = (high+low)/2;
        if(key == arr[mid]) return mid;
        else if(key > arr[mid]) low = mid+1;
        else high = mid-1;
    }
}

int main() {
    int key= 330;
    int arr[] = {1,22,330,444,550,634,799};
    
    int n =sizeof(arr)/sizeof(arr[0]);    
    int low = 0, high = n-1;

    int ans = binarySearch(arr,key,n,low,high);

    cout<<"Key at index :"<<ans<<endl;
    return 0;
}

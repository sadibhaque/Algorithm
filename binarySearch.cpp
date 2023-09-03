#include <bits/stdc++.h>

using namespace std;


int binarySearch(int arr[],int key,int n,int low,int high){
    int mid = (high+low)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(key > arr[mid]){
        low = mid+1;
        return binarySearch(arr,key,low,mid,high);
    }
    else{
        high = mid-1;
        return binarySearch(arr,key,low,mid,high);
    }

}

int main() {

    int key;

    cin>>key;

    int arr[] = {1,2,3,4,5,6,7};

    int n = 7;

    int low = arr[0], high = arr[n-1];

    int ans = binarySearch(arr,key,n,low,high);

    cout<<ans<<endl;

    return 0;
}

// Problem Link : https://codeforces.com/group/u3Ii79X3NY/contest/270254/problem/T

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define ll long long 



long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

long long ceil_div1(long long a, long long b) {
    if(a % b){
        return a + (b - (a % b)) / b;
    }else{
        return a / b;
    }
}


void solve(void){
    int n, k; cin >> n >> k;
    int arr[n]; map<int, int> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        m[arr[i]]++;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        int res = k - arr[i];
        if(m.count(res)){
            m[arr[i]]--;
            ans+=m[res];
        }
    }

    cout << ans << "\n";
}


void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(void){

    fastIO();
    solve();
    return 0;
}
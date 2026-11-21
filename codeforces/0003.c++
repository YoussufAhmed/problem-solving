// Problem Link : https://codeforces.com/problemset/problem/1133/B

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


void solve1(void){
    int n, k; cin >> n >> k;
    int arr[n]; map<int, int> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        m[arr[i]%k]++;
    }

    long long ans = 0;
    for(int i=0; i<n; i++){
        int needed = k -  (arr[i] % k) ;
        if(needed == k) needed =0;
        if(m.count(needed) && m[needed] > 1){
            m[arr[i]%k]--;
            ans+=2;
            m[needed]--;
        }
    }

    cout << ans << "\n";
    
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> cnt(k);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        cnt[x%k]++;
    }

    int ans = 0;
    ans += cnt[0]/2;
    if(k % 2 == 0){
        ans+=cnt[k/2]/2;
    }

    for(int i=1; i<(k+1)/2; i++){
        int target = k - i;
        ans+=min(cnt[i], cnt[target]);
    }

    cout << ans * 2 << "\n";
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
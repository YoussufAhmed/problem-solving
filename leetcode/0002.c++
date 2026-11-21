// problem link : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> m;
        int n = time.size();
        for(int i=0; i<n; i++){
            m[time[i]%60]++;
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            int target = 60 - (time[i]%60);
            if(target == 60) target = 0;
            if(m.count(target)){
                m[time[i]%60]--;
                ans+=m[target];
            }
        }
        return ans;
    }
};


int main(void){
    vector<int> v = {30, 20, 150, 100, 40};
    Solution s;
    int ans = s.numPairsDivisibleBy60(v);

    cout << ans << "\n";
}   
// problem link : https://leetcode.com/problems/find-pivot-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0; i<n; i++){
            if(i==0 && nums[n-1]-nums[i]==0) return 0;  //Edge case 1 : 
            if(i==n-1 && nums[i-1]==0) return i;  //Edge case 2 : 
            if(i != 0 && i != n-1)
               if(nums[i-1] == nums[n-1] - nums[i]) return i;
        }

        return -1;
    }
};


int main(void){

}
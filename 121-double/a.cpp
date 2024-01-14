#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; i ++) {
            if(nums[i] != nums[i-1]+1) break;
            sum += nums[i];
        }
        unordered_map<int, int> mp;
        for(auto& x: nums) mp[x] = 1;
        int ret = sum;
        while(mp.count(ret)) ret++;
        return ret;
    }
};
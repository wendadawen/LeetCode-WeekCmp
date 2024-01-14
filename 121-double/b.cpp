#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = 0;
        for(int j = 0; j < 32; j ++) {
            int a = k >> j & 1; int cnt = 0;
            for(int i = 0; i < n; i ++) {
                if(nums[i] >> j & 1) cnt ++;
            }
            if((cnt&1)!=a) ret++; 
        } 
        return ret;
    }
};
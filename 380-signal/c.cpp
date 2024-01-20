#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        auto check = [&](ll num)->bool {
            int n = 64 - __builtin_clzll(num);
            vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));
            auto dfs = [&](auto dfs, int i, bool limitUp, int cnt1)->ll {
                if(i < 0) return cnt1;
                if(!limitUp && dp[i][cnt1]!=-1) return dp[i][cnt1];
                int up = (limitUp) ? (num>>i)&1: 1;
                ll ret = 0;
                for(int d = 0; d <= up; d ++) {
                    ret += dfs(dfs, i-1, limitUp&&d==up, cnt1+(d==1&&(i+1)%x==0));
                }
                if(!limitUp) dp[i][cnt1] = ret;
                return ret;
            };
            return dfs(dfs, n-1, true, 0) <= k;
        };
        ll left = 0, right = (k + 1) << x;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};
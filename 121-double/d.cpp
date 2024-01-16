#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    // 数位DP板子题
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string num1 = to_string(start);
        string num2 = to_string(finish);
        int n = num2.size();
        int m = s.size();
        int dif = n - m;
        num1 = string(n-(int)num1.size(), '0') + num1;
        ll memo[n]; memset(memo, -1, sizeof(memo));
        auto dfs = [&](auto dfs, int i, bool limitUp, bool limitDn)->ll {
            if(i == n) return 1;
            int dn = (limitDn) ? num1[i]-'0': 0;
            int up = (limitUp) ? num2[i]-'0': 9;
            if(!limitUp && !limitDn && memo[i] != -1) return memo[i];
            ll ret = 0;
            if(i < dif) {
                for(int j = dn; j <= min(up, limit); j ++) {
                    ret += dfs(dfs, i+1, limitUp&&(j==up), limitDn&&(j==dn));
                }
            } else {
                int x = s[i-dif]-'0';
                if(x >= dn && x <= min(limit, up)) 
                    ret += dfs(dfs, i+1, limitUp&&(x==up), limitDn&&(x==dn));
            }
            if(!limitUp && !limitDn) memo[i] = ret;
            return ret;
        };
        return dfs(dfs, 0, true, true);
    }
};
#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        if (k >= 26)
            return 1;
        int n = s.size();
        auto get = [&](int x) -> int {
            int ret = 0;
            while (x){
                if (x & 1)
                    ret++;
                x >>= 1;
            }
            return ret;
        };
        unordered_map<long long, int> mp;
        auto dfs = [&](auto dfs, int i, int mask, int changed) -> int {
            if (i == n)
                return 1;
            int a = s[i] - 'a';
            long long args_mask = (long long) i << 32 | mask << 1 | changed;
            if(mp.count(args_mask)) return mp[args_mask];
            int ret = 0;
            if ((mask >> a) & 1)
                ret = max(ret, dfs(dfs, i + 1, mask, changed));
            else {
                if (get(mask) == k)
                    ret = max(ret, dfs(dfs, i + 1, (1 << a), changed) + 1);
                else
                    ret = max(ret, dfs(dfs, i + 1, mask | (1 << a), changed));
            }
            if (changed == 0) {
                for (int j = 0; j < 26; j++) {
                    a = j;
                    if ((mask >> a) & 1)
                        ret = max(ret, dfs(dfs, i + 1, mask, 1));
                    else {
                        if (get(mask) == k)
                            ret = max(ret, dfs(dfs, i + 1, (1 << a), 1) + 1);
                        else
                            ret = max(ret, dfs(dfs, i + 1, mask | (1 << a), 1));
                    }
                }
            }
            return mp[args_mask] = ret;
        };
        return dfs(dfs, 0, 0, 0);
    }
};
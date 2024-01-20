#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto& x: nums) cnt[x] ++;
        int mx = 0, ret = 0;
        for(auto&[u, v]: cnt) mx = max(mx, v);
        for(auto&[u, v]: cnt) if(v == mx) ret += mx;
        return ret;
    }
};
#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        int ret = 20000;
        int mx = max(x, y);
        auto get = [&](int a, int b)->int{
            if(b >= a) return b-a;
            queue<int> q; q.push(a); int ret = 0;
            unordered_map<int,int> mp;
            while(q.size()) {
                int siz = q.size();
                while(siz --) {
                    auto u = q.front(); q.pop();
                    if(u+1 == b) return ret+1;
                    if(u-1 == b) return ret+1;
                    if(u%5==0&&u/5==b) return ret+1;
                    if(u%11==0&&u/11==b) return ret+1;
                    if(u < 10001 && !mp.count(u+1)) q.push(u+1), mp[u+1]=1;
                    if(u > b && !mp.count(u-1)) q.push(u-1), mp[u-1]=1;
                    if(u % 5 == 0 && !mp.count(u/5)) q.push(u/5), mp[u/5]=1;
                    if(u % 11 == 0 && !mp.count(u/11)) q.push(u/11), mp[u/11]=1;
                }
                ret ++;
            }
            return ret;
        };
        // for(int i = 1; i <= mx; i ++) {
        //     ret = min(ret, get(x, i)+get(y, i));
        // }
        return get(x, y);
    }
};
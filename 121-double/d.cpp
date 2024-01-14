#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        ll num = 0; for(auto& c: s) num=num*10+c-'0';
        auto get = [&](ll x)->ll{
            if(x < num) return 0;
            
        };
        return get(finish) - get(start-1);
    }
};
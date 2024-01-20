#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ret;
        auto get = [&](string& a, int i)->bool {
            if(i + a.size() > s.size()) return false;
            return s.substr(i, a.size()) == a;
        };
        vector<int> v;
        for(int i = 0; i < s.size(); i ++) {
            if(get(b, i)) v.push_back(i);  
        }
        auto check = [&](int i)->bool {
            if(v.size() == 0) return false;
            auto it = lower_bound(v.begin(), v.end(), i);
            if(it == v.end()) {
                return abs(i-(*(prev(it)))) <= k;
            }
            if(it == v.begin()) {
                return abs(i-(*it)) <= k;
            }
            return abs(i-(*it)) <= k || abs(i-(*(prev(it)))) <= k;
        };
        for(int i = 0; i < s.size(); i ++) {
            if(get(a, i) && check(i)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ret;
        auto get = [&](string pa, string ma, vector<int>& v){
            int n = pa.size() - 1;
            int m = ma.size() - 1;

            vector<int> ne(n+1);
            ne[1] = 0;
            int i=2, len=0;
            while(i<=n) {
                if(pa[i] == pa[len+1]) ne[i++] = ++len;
                else {
                    if(len == 0) ne[i++] = 0;
                    else len = ne[len];
                }
            }

            i = 1; len = 0;
            while(i <= m) {
                if(ma[i] == pa[len+1]) ++i, ++len;
                else if(len>0)len=ne[len];
                else ++i;
                if(len==n) {
                    v.push_back(i - len - 1);
                    len = ne[len];
                }
            }
        };
        vector<int> v; 
        get(" " + b, " " + s, v);
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
        vector<int> va; 
        get(" " + a, " " + s, va);
        for(int i = 0; i < va.size(); i ++) {
            if(check(va[i])) ret.push_back(va[i]);
        }
        return ret;
    }
};
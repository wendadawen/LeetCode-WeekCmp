#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        double a = 0;
        int ret = 0;
        for(auto& v: dimensions) {
            double b = sqrt(v[0]*v[0]+v[1]*v[1]);
            if(a < b) {
                ret = v[0]*v[1];
                a = b;
            } else if(a == b) {
                ret = max(ret, v[0]*v[1]);
            }
        }
        return ret;
    }
};
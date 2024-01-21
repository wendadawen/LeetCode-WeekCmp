#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int minimumPushes(string s) {
        int n = s.size();
        if(n <= 8) return n;
        if(n <= 16) return 8 + (n-8)*2;
        if(n <= 24) return 24 + (n-16)*3;
        return 48 + (n-24)*4;
    }
};
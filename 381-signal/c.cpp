#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int minimumPushes(string word) {
        int cnt[26]{};
        for (char b: word) {
            cnt[b - 'a']++;
        }
        sort(cnt, cnt + 26, greater<int>());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += cnt[i] * ((i / 8) + 1);
        }
        return ans;
    }
};
#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int nn = n/2;
        unordered_map<int, int> cnt1, cnt2, cnt;
        for(auto& x: nums1) cnt1[x]++;
        for(auto& x: nums2) cnt2[x]++;
        int c1 = 0, c2 = 0;
        vector<int> a;
        for(auto&[u, v]: cnt1) {
            if(cnt2.count(u)==0) {
                if(c1 < nn)cnt[u]=1, c1++;
            } else a.push_back(u);
        }
        for(auto&[u, v]: cnt2) {
            if(cnt1.count(u)==0 && c2<nn) cnt[u]=1, c2++;
        }
        if(cnt.size() == n) return n;
        for(auto& x: a) {
            if(c1 < c2 && c1 < nn) cnt[x]=1, c1++;
            else if(c2 < c1 && c2 < nn) cnt[x]=1, c2++;
            else if(c1 == c2 && c1 < nn) cnt[x]=1, c1++;
        }
        return cnt.size();
    }
};
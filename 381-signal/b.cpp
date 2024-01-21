#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ret(n, 0);
        vector<int> e[n+1];
        for(int i = 0; i < n; i ++) {
            ret[i] = (n-1-i) * 2;
            if(i!=n-1) e[i+1].push_back(i+2);
            if(i!=0)   e[i+1].push_back(i);
        }
        e[x].push_back(y);
        e[y].push_back(x);
        auto dis = [&](int s, int e)->int{
            return abs(s - e);
        };
        auto bfs = [&](int s, vector<int>& vis){ // 1-n
            queue<int> q; q.push(s); vis[s] = 1;
            while(q.size()) {
                auto u = q.front(); q.pop();
                for(auto& v: e[u]) {
                    if(vis[v]) continue;
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        };
        vector<int> dx(n+1), dy(n+1);
        bfs(x, dx); bfs(y, dy);
        for(int i = 1; i <= n; i ++) {
            cout << dx[i] << " ";
        } cout << endl;
        for(int i = 1; i <= n; i ++) {
            cout << dy[i] << " ";
        } cout << endl;
        
        for(int i = 1; i <= n; i ++) {
            if(dx[i] > dy[i] || i == x) {
                if(i == y) continue;
                if(dy[i] <= dis(i, y)) {
                    ret[dis(i, y)-1] -= 2;
                    ret[dy[i]-2] += 2;
                }
            } else if(dy[i] > dx[i] || i == y) {
                if(i == x) continue;
                if(dx[i] <= dis(i, x)) {
                    ret[dis(i, x)-1] -= 2;
                    ret[dx[i]-2] += 2;
                }
            }
        }
        return ret;
    }
};
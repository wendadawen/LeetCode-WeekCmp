#include <bits/stdc++.h>
#define debug(x) cout<<"LINE:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;using ll=long long;using pii=pair<int,int>;
const int INF=numeric_limits<int>::max();const int P=1e9+7;
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if((a==e && b==f) || (c==e && d==f)) return 0;
        auto move = [&](int x, int y, int dx, int dy, int a, int b) {
            while(x>=1 && x<=8 && y>=1 && y<=8) {
                if(x==a && y==b) return false;
                if(x==e && y==f) return true;
                x += dx; y += dy;
            }
            return false;
        };
        if(move(a,b,0,1,c,d)) return 1;
        if(move(a,b,0,-1,c,d)) return 1;
        if(move(a,b,1,0,c,d)) return 1;
        if(move(a,b,-1,0,c,d)) return 1;

        if(move(c,d,1,1,a,b)) return 1;
        if(move(c,d,1,-1,a,b)) return 1;
        if(move(c,d,-1,1,a,b)) return 1;
        if(move(c,d,-1,-1,a,b)) return 1;
        return 2;
    }
};
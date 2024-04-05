#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <climits>
#include <stack>
#include <map>
#include <math.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

const int INF = 1987654321;
const int MAX = 400004;

struct POINT {
    int x, y1, y2, val;
};

struct SEGTREE {
    vector<int> cnt;
    vector<ll> rangeRet;
    vector<int> convertY;
    int len;

    SEGTREE(int n, vector<int>& Y) {
        convertY = Y;
        len = n;
        int powered = 1;
        while(powered < len)
            powered <<= 1;
        cnt.resize(powered * 2);
        rangeRet.resize(powered * 2);
    }

    ll update(int val, int l, int r, int node, int nLeft, int nRight) {
        // cnt를 일단 모두 갱신    
        if(r < nLeft || nRight < l) return 0;
        if(l <= nLeft && nRight <= r) cnt[node] += val;
        else {
            int mid = (nLeft + nRight) / 2;
            update(val, l, r, node * 2, nLeft, mid);
            update(val, l, r, node * 2 + 1, mid + 1, nRight);
        }

        if(cnt[node]) {     // 이 영역 전체가 타겟이라면 이 영역의 길이를 그대로 반환
            // cout << nRight + 1 << ", " << convertY[nRight + 1] << ", " << convertY[nLeft] << '\n';
            return rangeRet[node] = convertY[nRight + 1] - convertY[nLeft];
        } else {            // 타겟이 이 영역 전체가 아니라면 
            if(nLeft == nRight)     // 리프 노드이면서 이 영역이 포함되지 않는(cnt==0) 영역이라면 0을 반환
                return rangeRet[node] = 0;
            else                    // 리프 노드가 아니면서 이 영역 자체는 포함되지 않다면, 다른 사각형에 의해 포함되는 부분영역의 길이다 있다면 이것을 합해서 반환
                return rangeRet[node] = rangeRet[node * 2] + rangeRet[node * 2 + 1];
        }
    }

    ll update(int val, int l, int r) {
        return update(val, l, r, 1, 0, len - 1);
    }
};

int n;
vector<POINT> p;
vector<int> Y;
map<int, int> m;

bool compX(POINT& a, POINT& b) {
    return a.x < b.x;
}

void compressY() {
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for(int i = 0; i < Y.size(); i++) {
        m[Y[i]] = i;
        // cout << "(" << Y[i] << ", " << m[Y[i]] << ")\n";
    }
}

int main(void) {
    FASTIO;

    cin >> n;
    int x1, x2, y1, y2;
    
    for(int i = 0; i < n; i++) {
        cin >> x1 >> x2 >> y1 >> y2;
        Y.push_back(y1);// Y.push_back(y1 - 1);
        Y.push_back(y2);// Y.push_back(y2 - 1);
        p.push_back({x1, y1, y2, 1});
        p.push_back({x2, y1, y2, -1});
    }
    compressY();
    for(int i = 0; i < p.size(); i++) {
        p[i].y1 = m[p[i].y1];
        p[i].y2 = m[p[i].y2];
    }
    sort(p.begin(), p.end(), compX);

    SEGTREE tree(MAX, Y);
    long long ans = 0;
    int prevX = -1;
    for(auto& i : p) {
        ans += (i.x - prevX) * tree.rangeRet[1];
        prevX = i.x;
        tree.update(i.val, i.y1, i.y2 - 1);
    }
    cout << ans << '\n';

    return 0;
}
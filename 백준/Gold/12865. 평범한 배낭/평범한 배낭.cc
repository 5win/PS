#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<set>
#define endl '\n'
#define MAXX(x, y) (((x) > (y)) ? (x) : (y))
#define MINN(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;

const int INF = 1987654321;
const int MOD = 1000000007;

int n, k;
int cache[101][100001];
vector<pair<int, int>> item;

int solve(int idx, int wSum) {
    if( idx >= n || item[idx].first + wSum > k) {
        return 0;
    }
    int &ret = cache[idx][wSum];
    if(ret != -1)
        return ret;

    int sum = 0;
    sum = MAXX(sum, item[idx].second + solve(idx + 1, wSum + item[idx].first));
    sum = MAXX(sum, solve(idx + 1, wSum));

    return ret = sum;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        item.push_back({a, b});
    }
    sort(item.begin(), item.end());

    int ret = solve(0, 0);
    cout << ret << endl;
    
    return 0;
}
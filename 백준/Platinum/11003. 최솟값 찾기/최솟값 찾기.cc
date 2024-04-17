#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;

int n, l;

struct comp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        if(a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
}
};

int main(void) {
    FASTIO;

    cin >> n >> l;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    int input, idx;
    for(int i = 1; i <= n; i++) {
        cin >> input;
        pq.push({input, i});
        while(pq.top().second < i - l + 1)
            pq.pop();
        cout << pq.top().first << ' ';
    }

    return 0;
}
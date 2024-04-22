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

int n;
priority_queue<int> pq;
vector<int> cup[200001];


int main(void) {
    FASTIO;
    
    cin >> n;
    int d, v, maxD = 0;
    for(int i = 0; i < n; i++) {
        cin >> d >> v;
        cup[d].push_back(v);
        maxD = max(maxD, d);
    }

    int ans = 0;
    for(int i = maxD; i > 0; i--) {
        for(int j = 0; j < cup[i].size(); j++)
            pq.push(cup[i][j]); 
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
    
    return 0;
}
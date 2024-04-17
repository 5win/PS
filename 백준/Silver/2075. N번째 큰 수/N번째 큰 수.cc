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
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    FASTIO;

    cin >> n;
    int input;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            cin >> input;
            if(pq.size() == n) {
                if(pq.top() < input) {
                    pq.pop();
                    pq.push(input);
                }
            } else {
                pq.push(input);
            }
        }
    }
    cout << pq.top() << '\n';

    return 0;
}
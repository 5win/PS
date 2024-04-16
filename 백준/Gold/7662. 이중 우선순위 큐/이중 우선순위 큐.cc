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

int k;
map<int, int> m;
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<>> minPQ;

int main(void) {
    FASTIO;

    int t; cin >> t;
    while(t--) {
        while(!maxPQ.empty()) maxPQ.pop();
        while(!minPQ.empty()) minPQ.pop();
        m.clear();
        cin >> k;
        char c;
        int input;
        while(k--) {

            cin >> c >> input;
            if(c == 'D') {
                if(input == 1) {
                    while(!maxPQ.empty() && m[maxPQ.top()] == 0)
                        maxPQ.pop();
                    if(!maxPQ.empty()) {
                        m[maxPQ.top()] = m[maxPQ.top()] - 1;
                        maxPQ.pop();
                    }
                } else if(input == -1) {
                    while(!minPQ.empty() && m[minPQ.top()] == 0)
                        minPQ.pop();
                    if(!minPQ.empty()) {
                        m[minPQ.top()] = m[minPQ.top()] - 1;
                        minPQ.pop();
                    }
                }
            } else {
                if(m.find(input) == m.end())
                    m[input] = 1;
                else
                    m[input] = m[input] + 1;
                minPQ.push(input);
                maxPQ.push(input);
            }
        }
        while(!maxPQ.empty() && m[maxPQ.top()] == 0)
            maxPQ.pop();
        while(!minPQ.empty() && m[minPQ.top()] == 0)
            minPQ.pop();

        if(maxPQ.empty() && minPQ.empty())
            cout << "EMPTY\n";
        else {
            if(!maxPQ.empty()) cout << maxPQ.top() << ' ';
            if(!minPQ.empty()) cout << minPQ.top() << '\n';
        }
    }

    return 0;
}
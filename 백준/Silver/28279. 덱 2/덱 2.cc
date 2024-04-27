#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;


int main(void) {
    FASTIO;

    int n, a, b;
    deque<int> dq;

    cin >> n;
    while(n--) {
        cin >> a;
        switch(a) {
            case 1:
                cin >> b;
                dq.push_front(b);
                break;
            case 2:
                cin >> b;
                dq.push_back(b);
                break;
            case 3:
                if(!dq.empty()) {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                } else {
                    cout << "-1\n";
                }
                break;
            case 4:
                if(!dq.empty()) {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                } else {
                    cout << "-1\n";
                }
                break;
            case 5:
                cout << dq.size() << '\n';
                break;
            case 6:
                dq.empty() ? cout << "1\n" : cout << "0\n";
                break;
            case 7:
                dq.empty() ? cout << "-1\n" : cout << dq.front() << '\n'; 
                break;
            case 8:
                dq.empty() ? cout << "-1\n" : cout << dq.back() << '\n';
        }
    }

    return 0;
}
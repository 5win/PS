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

string s;
map<string, bool> m;

int main(void) {
    FASTIO;

    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            m[s.substr(i, j - i + 1)] = true;
        }
    }
    cout << m.size() << '\n';
    
    return 0;
}
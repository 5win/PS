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

int n, m;
string numToMon[100001];
map<string, int> monToNum;

int main(void) {
    FASTIO;

    string input;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> input;
        numToMon[i] = input;
        monToNum[input] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> input;
        if('0' <= input[0] && input[0] <= '9') {
            cout << numToMon[stoi(input)] << '\n';
        } else {
            cout << monToNum[input] << '\n';
        }
    }
    
    return 0;
}
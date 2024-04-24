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

int n;

void recursive(int k) {
    if(k == 1) {
        cout << '-';
        return;
    }

    int next = k / 3;
    recursive(next);
    for(int i = 0; i < next; i++)
        cout << ' ';
    recursive(next);
}

int main(void) {
    FASTIO;

    while(cin >> n) {
        if(cin.eof()) break;

        recursive(pow(3, n));
        cout << '\n';
    }

    
    return 0;
}
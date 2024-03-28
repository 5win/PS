#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1987654321;

string s;
int q;
int psum[200001][26];

int main(void) {
    FASTIO;

    cin >> s >> q;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < 26; j++)
            psum[i][j] = psum[i - 1][j];
        psum[i][s[i - 1] - 'a']++;
    }

    for(int i = 0; i < q; i++) {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        cout << psum[r + 1][alpha - 'a'] - psum[l][alpha - 'a'] << '\n';
    }

    return 0;
}
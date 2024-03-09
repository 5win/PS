#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n;
int paper[200][200];
int res[2];

bool canUse(int y, int x, int len) {
    int firstNum = paper[y][x];
    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++) {
            if(paper[i][j] != firstNum) return false;
        }
    }
    return true;
}

void dfs(int y, int x, int len) {

    if(len == 1) {
        res[paper[y][x]]++;
        return;
    }
    if(canUse(y, x, len)) {
        res[paper[y][x]]++;
        return;
    }

    int divLen = len / 2;
    for(int i = y; i < y + len; i += divLen) {
        for(int j = x; j < x + len; j += divLen) {
            dfs(i, j, divLen);
        }
    }
}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    dfs(0, 0, n);

    cout << res[0] << endl;
    cout << res[1] << endl;

    return 0;
}
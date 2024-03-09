#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n;
string arr[100];

bool canUse(int y, int x, int len) {
    char num = arr[y][x];

    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++) {
            if(arr[i][j] != num) return false;
        }
    }
    return true;
}

void dfs(int y, int x, int len) {

    if(len == 1) {
        cout << arr[y][x];
        return;
    }

    if(canUse(y, x, len)) {
        cout << arr[y][x];
        return;
    }

    cout << '(';
    int divLen = len / 2;
    for(int i = y; i < y + len; i += divLen) {
        for(int j = x; j < x + len; j += divLen) {
            dfs(i, j, divLen);
        }
    }
    cout << ')';
}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs(0, 0, n);

    return 0;
}
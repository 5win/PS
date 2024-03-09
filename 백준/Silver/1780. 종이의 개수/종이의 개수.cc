#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n;
int board[3001][3001];
int res[3];
const int NOTPAPER = -2;

int canPaper(int y, int x, int len) {
    int num = board[y][x];

    int cnt = 0;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(board[y + i][x + j] == num) cnt++;
            else return NOTPAPER;
        }
    }
    if(cnt == len * len) {
        return num;
    }
    return NOTPAPER;
}

void dfs(int y, int x, int len) {

    int pNum = canPaper(y, x, len);
    if(pNum != NOTPAPER) {
        res[pNum + 1]++;
        return;
    }

    int divLen = len / 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            dfs(y + i * divLen, x + j * divLen, divLen);
        }
    }
}

int main(void) {
cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, n);

    for(int i = 0; i < 3; i++)
        cout << res[i] << endl;

    return 0;
}
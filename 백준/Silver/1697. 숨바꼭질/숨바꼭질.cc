#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, k;
int board[100001];

bool inRange(int x) {
    return 0 <= x && x < 100001;
}

int main(void) {
    cin >> n >> k;

    memset(board, -1, sizeof(board));
    board[n] = 0;

    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int curCnt = board[cur];

        if(cur == k) {
            cout << curCnt << '\n';
            break;
        }

        if(inRange(cur - 1) && board[cur - 1] == -1) {
            board[cur - 1] = curCnt + 1;
            q.push(cur - 1);
        }
        if(inRange(cur + 1) && board[cur + 1] == -1) {
            board[cur + 1] = curCnt + 1;
            q.push(cur + 1);
        }
        if(inRange(cur * 2) && board[cur * 2] == -1) {
            board[cur * 2] = curCnt + 1;
            q.push(cur * 2);
        }
    }

    return 0;
}
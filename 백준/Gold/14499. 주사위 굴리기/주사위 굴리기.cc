#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int n, m, x, y, k;
int board[21][21];
int dice[4][4];

// 동서북남
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool inRange(int ny, int nx) {
    return 0 <= ny && ny < n && 0 <= nx && nx < m;
}

void rollRight() {

    int tmp[4];

    for(int i = 0; i < 4; i++)
        tmp[(i + 1) % 4] = dice[1][i];
    for(int i = 0; i < 4; i++)
        dice[1][i] = tmp[i];
    dice[3][1] = dice[1][3];
}

void rollDown() {
    int tmp[4];

    for(int i = 0; i < 4; i++)
        tmp[(i + 1) % 4] = dice[i][1];
    for(int i = 0; i < 4; i++)
        dice[i][1] = tmp[i];
    dice[1][3] = dice[3][1];
}

void rollDice(int dir) {
    
    if(dir == 0) {
        for(int i = 0; i < 3; i++)
            rollRight();
    }
    else if(dir == 1) {
        rollRight();
    }
    else if(dir == 2) {
        for(int i = 0; i < 3; i++)
            rollDown();
    }
    else
        rollDown();
}

int main(void) {

    cin >> n >> m >> y >> x >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int dir;
    while(k--) {
        cin >> dir;
        dir--;

        if(!inRange(y + dy[dir], x + dx[dir])) continue;

        y += dy[dir];
        x += dx[dir];
        rollDice(dir);
        if(board[y][x] == 0) {
            board[y][x] = dice[1][3];
        }
        else {
            dice[1][3] = dice[3][1] = board[y][x];
            board[y][x] = 0;
        }
        cout << dice[1][1] << endl;
    }

    return 0;
}
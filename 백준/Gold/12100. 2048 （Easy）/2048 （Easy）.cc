#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<numeric>

#define endl '\n'

using namespace std;
const int INF = 1987654321;
const int MAX = 1000 * 1000 * 10;
const int _MOD = 1000000007;

int n;
int board[21][21];

// 좌우 반전
void switchRL() {
    int temp[21][21];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            temp[i][j] = board[i][n - j - 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = temp[i][j];
}

// 상화 반전
void switchUD() {
    int temp[21][21];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = board[n - i - 1][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = temp[i][j];
}

void moveRight() {
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            if(board[i][j] == 0) {
                for(int k = j - 1; k >= 0; k--) {
                    if(board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > 0; j--) {
            if(board[i][j] == board[i][j - 1]) {
                board[i][j] += board[i][j];
                board[i][j - 1] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            if(board[i][j] == 0) {
                for(int k = j - 1; k >= 0; k--) {
                    if(board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void moveUp() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[j][i] == 0) {
                for(int k = j + 1; k < n; k++) {
                    if(board[k][i] != 0) {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(board[j][i] == board[j + 1][i]) {
                board[j][i] += board[j][i];
                board[j + 1][i] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[j][i] == 0) {
                for(int k = j + 1; k < n; k++) {
                    if(board[k][i] != 0) {
                        board[j][i] = board[k][i];
                        board[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int solve(int cnt) {
    if(cnt == 5) {
        int _max = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                _max = max(_max, board[i][j]);
        return _max;
    }

    int temp[21][21];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = board[i][j];

    // 상 하 좌 우
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        if(i == 0) 
            moveUp();
        else if(i == 1) {
            switchUD();
            moveUp();
            switchUD();
        }
        else if(i == 2) {
            switchRL();
            moveRight();
            switchRL();
        }
        else 
            moveRight();
        
        ret = max(ret, solve(cnt + 1));
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                board[j][k] = temp[j][k];
    }
    return ret;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   
   
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    cout << solve(0) << endl;

    return 0;
}

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
int m, k;
int r, c;
int sticker[11][11];
int arr[41][41];

// 빈칸의 개수 카운트
int countEmtpy() {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j]) {
                ret++;
            }
        }
    }
    return ret;
}

// 스티커를 90도 회전
void rotate() {
    int temp[11][11];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            temp[j][r - i - 1] = sticker[i][j];
        }
    }
    swap(r, c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sticker[i][j] = temp[i][j];
        }
    }
}

// 해당 자리에 스티커가 붙을 수 있는지 확인 or 붙임(true, false)
bool canStick(int y, int x, bool isCheck) {
    if(isCheck) {
        for(int i = y; i < y + r; i++) {
            for(int j = x; j < x + c; j++) {
                if(sticker[i - y][j - x] && arr[i][j])
                    return false;
            }
        }
        return true;
    }
    else {
        for(int i = y; i < y + r; i++) {
            for(int j = x; j < x + c; j++) {
                if(sticker[i - y][j - x])
                    arr[i][j] = 1;
            }
        }
        return true;
    }
}

// 해당 스티커를 붙이는 작업
void solve() {
    for(int rot = 0; rot < 4; rot++) {
        for(int i = 0; i < n - r + 1; i++) {
            for(int j = 0; j < m - c + 1; j++) {        // 회전시 r, c도 바꿔줘야함
                if(canStick(i, j, true)) {
                    canStick(i, j, false);
                    return;
                }
            }
        }
        rotate();
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        memset(sticker, 0, sizeof(sticker));
        cin >> r >> c;
        for(int j = 0; j < r; j++) {
            for(int l = 0; l < c; l++) {
                cin >> sticker[j][l];
            }
        }
        solve();
    }
    cout << countEmtpy() << endl;    

    return 0;
}
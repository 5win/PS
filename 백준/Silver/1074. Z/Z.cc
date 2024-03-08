#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, r, c;
int cnt, ret;

void dfs(int num, int row, int col) {

    if(num == 0) {
        if(row == r && col == c) 
            ret = cnt;
        cnt++;
        return;
    }

    int divLen = 1 << (num - 1);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int ny = row + i * divLen;
            int nx = col + j * divLen;

            if(ny <= r && r < ny + divLen && nx <= c && c < nx + divLen) {
                dfs(num - 1, ny, nx);
            }
            else {
                cnt += divLen * divLen;
            }
        }
    }

}

int main(void) {
    cin >> n >> r >> c;

    dfs(n, 0, 0);
    cout << ret << endl;

    return 0;
}
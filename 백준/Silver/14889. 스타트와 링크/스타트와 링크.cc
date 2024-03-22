#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

const int INF = 1987654321;
int n;
int stat[21][21];
bool linkTeam[21];
int res = INF;

void calcStat() {
    int startStat = 0;
    int linkStat = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(linkTeam[i] && linkTeam[j]) {
                linkStat += stat[i][j] + stat[j][i];
            }
            else if(!linkTeam[i] && !linkTeam[j]) {
                startStat += stat[i][j] + stat[j][i];
            }
        }
    }
    res = min(res, abs(startStat - linkStat));
}

void dfs(int lNum, int start) {

    if(lNum == n / 2) {
        calcStat();
        return;
    }

    for(int i = start; i < n; i++) {
        linkTeam[i] = true;
        dfs(lNum + 1, i + 1);              // select
        linkTeam[i] = false;
    }
}

int main(void) {

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> stat[i][j];
        }
    }
    dfs(0, 0);
    cout << res << endl;

    return 0;
}
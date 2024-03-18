#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>
#include<stack>

using namespace std;
const int INF = 987654321;
int n, m;
vector<int> v;
int visited[16][16];

void removeCanVisit(int y, int x, int q) {
    // 상하좌우
    for(int i = 0; i < n; i++) {
        if(visited[y][i] == q)
            visited[y][i] = -1;
        if(visited[i][x] == q)
            visited[i][x] = -1;
    }
    // right down 대각
    int i = y, j = x;
    while(i < n && j < n) {
        if(visited[i][j] == q)
            visited[i][j] = -1;
        i++;
        j++;
    }
    // left down
    i = y;
    j = x;
    while(i < n && j >= 0) {
        if(visited[i][j] == q)
            visited[i][j] = -1;
        i++;
        j--;
    }
    // left up
    i = y;
    j = x;
    while(i >= 0 && j >= 0) {
        if(visited[i][j] == q)
            visited[i][j] = -1;
        i--;
        j--;
    }
    // right up
    i = y;
    j = x;
    while(i >= 0 && j < n) {
        if(visited[i][j] == q)
            visited[i][j] = -1;
        i--;
        j++;
    }
    return;
}

void checkCanVisit(int y, int x, int q) {
    // 상하좌우
    for(int i = 0; i < n; i++) {
        if(visited[y][i] == -1)
            visited[y][i] = q;
        if(visited[i][x] == -1)
            visited[i][x] = q;
    }
    // right down 대각
    int i = y, j = x;
    while(i < n && j < n) {
        if(visited[i][j] == -1)
            visited[i][j] = q;
        i++;
        j++;
    }
    // left down
    i = y;
    j = x;
    while(i < n && j >= 0) {
        if(visited[i][j] == -1)
            visited[i][j] = q;
        i++;
        j--;
    }
    // left up
    i = y;
    j = x;
    while(i >= 0 && j >= 0) {
        if(visited[i][j] == -1)
            visited[i][j] = q;
        i--;
        j--;
    }
    // right up
    i = y;
    j = x;
    while(i >= 0 && j < n) {
        if(visited[i][j] == -1)
            visited[i][j] = q;
        i--;
        j++;
    }
    return;
}

int solve(int start, int count) {

    /*for(int i = 0; i < n; i++) {
        for(int  j = 0; j < n; j++)
            printf("%2d", visited[i][j]);
        cout << endl;
    }
    cout << endl;
*/
   // cout << start << '\n';
    if(count == n + 1)
        return 1;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(visited[start][i] == -1) {
            checkCanVisit(start, i, count);
            sum += solve(start + 1, count + 1);
            removeCanVisit(start, i, count);
        }
    }
    // 뻘짓하면서 만든 식
    /*int sum = 0;
    int j = start % n;
    for(int i = start / n; i < n; i++) {
        if(n - count > n - i) break;
        while(j < n) {
            if(visited[i][j] == -1) {
                checkCanVisit(i, j, count);
                sum += solve(n * (i + 1) - 1, count + 1);
                removeCanVisit(i, j, count);
            }
            j++;
        }
        j = 0;
    }
    */
    
    return sum;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 16; i++)
        memset(visited[i], -1, sizeof(visited[i]));

    cin >> n;

    int ret = 0;
    for(int i = 0; i < n; i++) {
        checkCanVisit(0, i, 1);
        ret += solve(1, 2);
        removeCanVisit(0, i, 1);
    }
   
    cout << ret << endl;
    
    return 0;
}
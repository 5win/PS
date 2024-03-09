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

using namespace std;
const int INF = 1987654321;
const int MAX = 101;
const int _MOD = 1000000007;

int n, k;
int arr[2200][2200];
int ret[3];

bool canUse(int y, int x, int size) {
    int num = arr[y][x];

    for(int i = y; i < y + size; i++) 
        for(int j = x; j < x + size; j++) 
            if(arr[i][j] != num) return false;
    return true;
}

void solve(int y, int x, int size) {
    if(size == 1) {
        if(arr[y][x] == -1) ret[0]++;
        else if(arr[y][x] == 0) ret[1]++;
        else ret[2]++;
        return;
    }

    if(canUse(y, x, size)) {
        if(arr[y][x] == -1) ret[0]++;
        else if(arr[y][x] == 0) ret[1]++;
        else ret[2]++;
        return;
    }
    
    int len = size / 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            solve(y + i * len, x + j * len, len);
        }
    }
    return;    
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0, 0, n);

    for(int i = 0; i < 3; i++)
        cout << ret[i] << endl;

    return 0;
}
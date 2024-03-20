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
const int MAX = 1000001;
int cache[501][501];
int arr[501][501];

int t,n;


int solve(int start, int col) {
    if(start == n - 1)
        return arr[start][col];

    int &ret = cache[start][col];
    if(ret != -1)
        return ret;

    int sum = 0;
    sum = arr[start][col] + max(solve(start + 1, col), solve(start + 1, col + 1));
    
    return ret = sum;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < 501; i++)
        memset(cache[i], -1, sizeof(cache[i]));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve(0, 0) << endl;
    
    return 0;
}
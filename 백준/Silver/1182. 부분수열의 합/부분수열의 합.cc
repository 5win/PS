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
#include<numeric>

#define endl '\n'

using namespace std;
const int INF = 1987654321;
const int MAX = 1000 * 1000 * 10;
const int _MOD = 1000000007;

int n;
int s;
int arr[21];
int cnt = 0;

void solve(int start, int sum) {
    if(sum == s) {
        cnt++;
    }
    for(int i = start + 1; i < n; i++) {
         solve(i, sum + arr[i]);
    }
    return;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    for(int i = 0; i < n; i++) {
        solve(i, arr[i]);
    }
    cout << cnt << endl;

    return 0;
}
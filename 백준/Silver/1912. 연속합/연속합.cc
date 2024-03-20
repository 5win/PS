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
const int MAX = 100001;

int n, k;
string s1, s2;
int cache[MAX];
int arr[MAX];

int solve(int start) {
    if(start == n)
        return 0;

    int &ret = cache[start];
    if(ret != -INF)
        return ret;

    int m = max(arr[start], arr[start] + solve(start + 1));

    return ret = m;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < MAX; i++)
        cache[i] = -INF;

    cin >> n;
    for(int i = 0; i < n ; i++)
        cin >> arr[i];

    int m = -INF;
    for(int i = 0; i < n; i++) {
        m = max(m, solve(i));
    }
    cout << m << endl;

    return 0;
}
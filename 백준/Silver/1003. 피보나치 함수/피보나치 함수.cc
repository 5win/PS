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

int t,n;

int cache0[41] = {1, 0, 1};
int cache1[41] = {0, 1, 1};

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    for(int j = 3; j <= 40; j++) {
        cache0[j] = cache0[j - 1] + cache0[j - 2];
        cache1[j] = cache1[j - 1] + cache1[j - 2];
    }
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << cache0[n] << ' ' << cache1[n] << endl;
    }

    return 0;
}
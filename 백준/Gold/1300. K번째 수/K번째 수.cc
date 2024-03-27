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
#include<map>

using namespace std;
const int INF = 1987654321;
const int MAX = 101;
const int _MOD = 1000000007;

int n, k;

/*
1 2 3
2 4 6
3 6 9

1 2 2 3 3 4 6 6 9

1 2 3 4
2 4 6 8
3 6 9 12
4 8 12 16

1 ~ 2n - 1


1 2 3 4 5 6
2 4 6 8 10 12
3 6 9 12 15 18
4 8 12 16 20 24
5 10 15 20 25 30
6 12 18 24 30 36
*/

int search() {
    int start = 1, end = k;
    int ret;
    while(start <= end) {
        int mid = (start + end) / 2;
        long long count = 0;
        for(int i = 1; i <= n; i++) {
            count += min(mid / i, n);
        }
        if(count >= k) {
            ret = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ret;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    
    cout << search() << endl;

    return 0;
}
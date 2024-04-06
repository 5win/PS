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

using namespace std;
const int INF = 1987654321;
const int MAX = 101;
const int _MOD = 1000000007;

int n, m;
vector<int> tree;
vector<int> ret;

long long cal(int mid) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if(tree[i] > mid)
            sum += (tree[i] - mid);
    }
    return sum;
}

int solve() {

    int start = 0, end = tree[n - 1];
    while(start + 1 < end) {
        int mid = (start + end) / 2;

        long long result = cal(mid);
        if(result >= m)
            start = mid;
        else
            end = mid;
    }

    return start;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }
    sort(tree.begin(), tree.end());

    int res = solve();

    cout << res << endl;

    return 0;
}
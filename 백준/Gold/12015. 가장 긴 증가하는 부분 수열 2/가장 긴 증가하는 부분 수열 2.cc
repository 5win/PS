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

int n;
vector<int> v;
vector<int> ret;


int solve() {
    ret.push_back(-INF);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(ret.back() < v[i]) {
            ret.push_back(v[i]);
            cnt++;
        }
        else {
            vector<int>::iterator it = lower_bound(ret.begin(), ret.end(), v[i]);
            *it = v[i];
        }
    }
    return cnt;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << solve() << endl;
    

    return 0;
}
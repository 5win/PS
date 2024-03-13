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
int m;
int arr[10];
bool visited[10];
vector<int> v;

void solve(int start, int len) {
    if(len == m) {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            v.push_back(arr[i]);
            visited[i] = true;
            solve(i, len + 1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    sort(arr, arr + n);

    solve(0, 0);
    
    return 0;
}
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
bool visited[10] = {0, };

void solve(int count) {

    if(count == m + 1) {
        for(int i = 0; i < v.size(); i++) 
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            solve(count + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
    return;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    solve(1);
    
    return 0;
}
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
#include<limits>
#include<algorithm>

using namespace std;
int n;

void solve2(int c, int from, int mid, int to) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(c == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    solve2(c - 1, from, to, mid);
    cout << from << ' ' << to << '\n';
    solve2(c - 1, mid, from, to);
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    cout << (1 << n) - 1 << '\n';
    solve2(n, 1, 2, 3);

    return 0;
}
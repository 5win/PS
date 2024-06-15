#include <bits/stdc++.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

// const int INF = 1987654321;
const int INF = 1e9;
const int MOD = 1e9;
const int MAX = 40001;

int m;

int main(void) {
    FASTIO;

    string oper;
    int x, s = 0;
    cin >> m;
    while(m--) {
        cin >> oper;
        if(oper == "add") {
            cin >> x;
            s = s | (1 << x);
        } else if(oper == "remove")  {
            cin >> x;
            s &= ~(1 << x);
        } else if(oper == "check") {
            cin >> x;
            if((s & (1 << x)))
                cout << "1\n";
            else
                cout << "0\n";
        } else if(oper == "toggle") {
            cin >> x;
            s ^= (1 << x);
        } else if(oper == "all") {
            s = (1 << 21) - 1;
        } else if(oper == "empty") {
            s = 0;
        }
    }

    return 0;
}
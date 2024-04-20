#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long

const int INF = 1987654321;
const int MOD = 1000000007;


int main(void) {
    FASTIO;

    int n, m, num;
    map<int, int> card;
    cin >> n;
    
    while(n--) {
        cin >> num;
        card[num] = num;
    }
    cin >> m;
    while(m--) {
        cin >> num;
        if(card.find(num) == card.end())
            cout << "0 ";
        else
            cout << "1 ";
    }

    
    return 0;
}
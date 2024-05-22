#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <stack>
#include <math.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define ULL unsigned long long

const int INF = 1987654321;
const int MOD = 1000000007;

int main(void) {
    FASTIO;

    string input;
    cin >> input;

    vector<string> token;

    int s = 0, e = 1;
    while(e <= input.size()) {
        if(input[e] == '-' || e == input.size()) {
            token.push_back(input.substr(s, e - s));
            s = e + 1;
            e = s + 1;
        } else {
            e++; 
        }
    }

    s = 0; e = 1;
    int res = 0;
    while(e <= token[0].size()) {
        if(token[0][e] == '+' || e == token[0].size()) {
            res += stoi(token[0].substr(s, e - s));
            s = e + 1;
            e = s + 1;
        } else {
            e++;
        }
    }
    for(int i = 1; i < token.size(); i++) {
        int sum = 0;
        s = 0; e = 1;
        while(e <= token[i].size()) {
            if(token[i][e] == '+' || e == token[i].size()) {
                sum += stoi(token[i].substr(s, e - s));
                s = e + 1;
                e = s + 1;
            } else {
                e++;
            }
        }
        res -= sum;
    }
    cout << res << '\n';

    return 0;
}
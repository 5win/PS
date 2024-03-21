#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n) {
    
   	long long dp[5001] = {0, };
    dp[2] = 3;
   	dp[3] = 0;
    dp[4] = 11;
    for(int i = 5; i <= n; i++) {
        dp[i] = (dp[i - 2] * 3) % MOD;
        if(i % 2 == 0) {
        	dp[i] = (dp[i] + 2) % MOD;
            for(int j = 4; i - j > 0; j += 2)
                dp[i] = (dp[i] + dp[i - j] * 2) % MOD;
        }
        
    }
    
    return dp[n];
}
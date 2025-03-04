class Solution {
    public int solution(int n, int m, int[] section) {
        
        int ans = 1;
        int limit = section[0] + m;
        for(int i = 0; i < section.length; i++) {
            int cur = section[i];
            if(cur < limit) {
                continue;
            } else {
                limit = cur + m;
                ans++;
            }
        }
        
        return ans;
    }
}
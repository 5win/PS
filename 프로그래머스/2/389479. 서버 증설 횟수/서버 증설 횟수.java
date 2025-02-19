class Solution {
    public int solution(int[] players, int m, int k) {
        
        int[] timeover = new int[50];
        
        int server = 0;
        int ans = 0;
        
        for(int i = 0; i < players.length; i++) {
           	int cur = players[i];
            server -= timeover[i];
            if(cur / m > server) {
                int amount = cur / m - server;
                server += amount;
                ans += amount;
                timeover[i + k] += amount;
            }
        }
        return ans;
    }
}
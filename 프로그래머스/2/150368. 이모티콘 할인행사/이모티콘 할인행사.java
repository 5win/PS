import java.util.*;

class Solution {
    
   	class Pair implements Comparable<Pair> {
       	int fir, sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Pair p) {
            if(fir == p.fir)
                return p.sec - sec;
            return p.fir - fir;
        }
    } 
    
   	int[][] users;
    int[] emo;
    int[] sales;
    List<Pair> res = new ArrayList<>();
    
    void calc() {
       	
        int enroll = 0;
        int costSum = 0;
        for(int i = 0; i < users.length; i++) {
            int sum = 0;
            for(int j = 0; j < emo.length; j++) {
                if(sales[j] >= users[i][0]) {
                	int cost = emo[j] / 100 * (100 - sales[j]);
                    sum += cost;
                }
            }
            if(sum >= users[i][1]) {
                enroll++;
            } else {
                costSum += sum;
            }
        }
        res.add(new Pair(enroll, costSum));
    }
    
    void dfs(int here) {
       	if(here == emo.length) {
           	calc();
            return;
        } 
        
        for(int sale : new int[] {10, 20, 30, 40}) {
           	sales[here] = sale;
            dfs(here + 1);
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = {};
       	
       	this.users = users;
        this.emo = emoticons;
       	sales = new int[emo.length]; 
        
        dfs(0);
        Collections.sort(res);
       	
        answer = new int[] {res.get(0).fir, res.get(0).sec};
        
        return answer;
    }
}
import java.util.*;

class Mine {
    int dia, iron, stone;
    
    public Mine(int a, int b, int c) {
       	dia = a;
        iron = b;
        stone = c;
    }
}

class Solution {
    
	List<Mine> mine = new ArrayList<>();
    
    public int calcScore(int pick, Mine mine) {
        int ret = 0;
        if(pick == 0) {
          	ret += mine.dia + mine.iron + mine.stone;
        } else if(pick == 1) {
          	ret += 5 * mine.dia + mine.iron + mine.stone;  
        } else if(pick == 2) {
          	ret += 25 * mine.dia + 5 * mine.iron + mine.stone;  
        }
        return ret;
    }
    
    public int solution(int[] picks, String[] mines) {
        
        int picksSum = (int) Arrays.stream(picks).sum();
        
        int dia = 0, iron = 0, stone = 0;
		for(int i = 0; i < mines.length; i++) {
            if(mines[i].equals("diamond")) {
               	dia++; 
            } else if(mines[i].equals("iron")) {
               	iron++; 
            } else if(mines[i].equals("stone")) {
                stone++;
            }
            
            if((i + 1) % 5 == 0 || i + 1 == mines.length) {
                mine.add(new Mine(dia, iron, stone));
                dia = iron = stone = 0;
            }
            if(i + 1 == picksSum * 5) break;
        }        
        
        // sort
        Collections.sort(mine, (a, b) -> {
            if(a.dia == b.dia) {
                if(a.iron == b.iron) {
                    return b.stone - a.stone;
                }
                return b.iron - a.iron;
            }
            return b.dia - a.dia;
        });
        
        // calc
        int res = 0;
        for(Mine i : mine) {
            if(picks[0] > 0) {
                res += calcScore(0, i);
                picks[0]--;
            } else if(picks[1] > 0) {
                res += calcScore(1, i);
                picks[1]--;
            } else if(picks[2] > 0) {
                res += calcScore(2, i);
                picks[2]--;
            }
        }
        return res;
    }
}
class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        
       	int t = 1;
        int hp = health;
       	int attackIdx = 0; 
        int combo = 0;
        while(attackIdx < attacks.length) {
            
            // attack
       		if(attacks[attackIdx][0] == t) {
               	hp -= attacks[attackIdx][1];
                attackIdx++;
                
                // dead
                if(hp <= 0) {
                    return -1;
                }
                
                combo = 0;
                t++;
                continue;
            }
            
            
           	// heal
            combo++;
           	if(combo == bandage[0]) {
                hp = Math.min(health, hp + bandage[1] + bandage[2]);
                combo = 0;
            } else {
                hp = Math.min(health, hp + bandage[1]);
            }
            t++;
        }
       	
        return hp;
    }
}
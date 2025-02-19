class Solution {
    public int solution(int n, int w, int num) {
        n--;
        num--;
        
        int startRow = num / w;
        int startRemain = num % w;
        int startCol = startRow % 2 != 0 ? w - 1 - startRemain : startRemain;
        
       	int endRow = n / w;
        int endRemain = n % w;
        int endCol = endRow % 2 != 0 ? w - 1 - endRemain : endRemain;
        
        if(endRow % 2 == 0) {
            return endRow - startRow + (startCol <= endCol ? 1 : 0);
        } else {
           	return endRow - startRow + (startCol < endCol ? 0 : 1); 
        }
    }
}
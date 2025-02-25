import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        
        int n = numbers.length;
        Stack<Integer> st = new Stack<>();
       	int[] res = new int[n];
        
        // init
        res[n - 1] = -1;
        st.push(numbers[n - 1]);
        
        for(int i = n - 2; i >= 0; i--) {
            int cur = numbers[i];
            while(!st.isEmpty() && st.peek() <= cur) {
                st.pop();
            }
            
            res[i] = st.isEmpty() ? -1 : st.peek();
            st.push(cur);
        }
        
        return res;
    }
}
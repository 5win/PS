class Solution {
    public int[] solution(int[] arr, int[] query) {
        int[] answer = {};
       	
        answer = arr;
        for(int i = 0; i < query.length; i++) {
           	if(i % 2 == 0) {
                arr = new int[query[i] + 1];
                for(int j = 0; j <= query[i]; j++)
                   	arr[j] = answer[j];
               	answer = arr;
            } else {
                arr = new int[answer.length - query[i]];
                for(int j = query[i]; j < answer.length; j++)
                    arr[j - query[i]] = answer[j];
               	answer = arr;
            }
        }
        
        return answer;
    }
}
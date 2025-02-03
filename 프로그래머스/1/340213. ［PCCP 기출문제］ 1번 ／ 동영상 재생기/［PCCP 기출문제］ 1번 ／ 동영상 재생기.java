class Solution {
    public int convertToSec(String time) {
   		String[] ms = time.split(":");
        return Integer.parseInt(ms[0]) * 60 + Integer.parseInt(ms[1]);
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int vt = convertToSec(video_len);
        int pt = convertToSec(pos);
        int os = convertToSec(op_start);
        int oe = convertToSec(op_end);
           
        for(String cmd : commands) {
        	if(os <= pt && pt <= oe) {
                pt = oe;
            }    
            
            if(cmd.equals("prev")) {
               	pt = Math.max(0, pt - 10); 
            } else {
               	pt = Math.min(vt, pt + 10); 
            }
        }
        if(os <= pt && pt <= oe) {
            pt = oe;
        }    
        
        return String.format("%02d", pt / 60) + ":" + String.format("%02d", pt % 60);
    }
}
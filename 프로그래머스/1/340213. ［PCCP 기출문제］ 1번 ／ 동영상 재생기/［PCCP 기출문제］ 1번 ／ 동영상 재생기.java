class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        String[] videoTime = video_len.split(":");
        String[] posTime = pos.split(":");
        String[] opStart = op_start.split(":");
        String[] opEnd = op_end.split(":");
            
        int vm = Integer.parseInt(videoTime[0]);
        int vs = Integer.parseInt(videoTime[1]);
        int pm = Integer.parseInt(posTime[0]);
        int ps = Integer.parseInt(posTime[1]);
        int osm = Integer.parseInt(opStart[0]);
        int oss = Integer.parseInt(opStart[1]);
        int oem = Integer.parseInt(opEnd[0]);
        int oes = Integer.parseInt(opEnd[1]);
           
        for(String cmd : commands) {
            if((osm < pm || (osm == pm && oss <= ps)) && (pm < oem || (pm == oem && ps <= oes))) {
                pm = oem;
                ps = oes;
            }
            
            if(cmd.equals("prev")) {
                if(pm == 0 && ps < 10) {
                    ps = 0;
                } else if(pm > 0 && ps < 10) {
                    pm--;
                    ps = 60 - (10 - ps);
                } else {
                    ps -= 10;
                }
            } else {
                if(pm == vm && vs - ps < 10) {
                    ps = vs; 
                } else if(pm < vm && ps >= 50) {
                    pm++;
                    if(pm == vm) {
                        ps = Math.min(vs, ps - 50);
                    } else {
                    	ps = ps - 50;
                    }
                } else {
                    ps += 10;
                }
            }
        }
        if((osm < pm || (osm == pm && oss <= ps)) && (pm < oem || (pm == oem && ps <= oes))) {
            pm = oem;
            ps = oes;
        }
        
        answer = String.format("%02d", pm) + ":" + String.format("%02d", ps);
        
        return answer;
    }
}
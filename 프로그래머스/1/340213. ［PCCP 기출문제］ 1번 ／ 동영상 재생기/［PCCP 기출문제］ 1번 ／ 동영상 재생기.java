class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        int videoI = Integer.parseInt(video_len.substring(0,2)) * 60 + Integer.parseInt(video_len.substring(3,5));
        // 현재 위치
        int posI = Integer.parseInt(pos.substring(0,2)) * 60 + Integer.parseInt(pos.substring(3,5));
        int opStartI = Integer.parseInt(op_start.substring(0,2)) * 60 + Integer.parseInt(op_start.substring(3,5));
        int opEndI = Integer.parseInt(op_end.substring(0,2)) * 60 + Integer.parseInt(op_end.substring(3,5));


        for(int i=0;i<commands.length;i++) {
            if(opStartI <= posI && posI <= opEndI) {
                posI = opEndI;
            }
            
            if(commands[i].equals("prev")) {
                posI = Math.max(0, posI - 10);
            }
            else if(commands[i].equals("next")) {
                posI = Math.min(videoI, posI + 10);
            }
            
            if(opStartI <= posI && posI <= opEndI) {
                posI = opEndI;
            }
        }

        String hour = Integer.toString(posI / 60);
        String minute = Integer.toString(posI % 60);
        
        if(hour.length() == 1) {
            hour = "0" + hour;
        }
        if(minute.length() == 1) {
            minute = "0" + minute;
        }
        
        return hour + ":" + minute;
    }
}

// AA:BB 나눠서 AA*60 + BB
// op_start, op_end 다 바꿔놓기
// 이걸로 prev하면 -10이고 min() 이거 쓸 수 있는지 확인 Math.min()으로 해결
// next하면 +10이고 Math.max() 이걸로 최대 길이 확인 및 설정
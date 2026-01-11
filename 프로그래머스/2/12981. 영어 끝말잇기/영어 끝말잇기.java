import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {0, 0};

        char lastWord = '\n';
        Set<String> wordSet = new HashSet<>();
        for(int i=0;i<words.length;i++) {
            String currentWord = words[i];
            
            if(i == 0 || (lastWord == currentWord.charAt(0) && !wordSet.contains(currentWord))) {
                wordSet.add(currentWord);
                lastWord = currentWord.charAt(currentWord.length() - 1);
            }else {
                answer = new int[]{i % n + 1, i / n + 1};
                break;
            }
        }
        
        return answer;
    }
    
    // result 는 {0.0} 으로 선언
    // index 0에 해당하는 값이 나온다면 해당 index의 위치를 확인한다.
    // index % n + 1 이 result의 첫번째 값.
    // index / n + 1 이 result의 두번째 값.
    // for문으로 words의 length만큼 순회
    // for문 밖에서 char lastWord 선언
    // index != 0 일때만 lastWord의 값과 해당 index의 String.charAt(0)값이 같은지 확인
    // 같다면 pass, 다르다면 result 값 세팅해주고 break; result 값은 2,3라인에 정의함
    // Set.get(words[index])가 not null 이라면 result 값 세팅하고 break;
    // 현재 index 값을 Set에 저장.
    // result 제출
}
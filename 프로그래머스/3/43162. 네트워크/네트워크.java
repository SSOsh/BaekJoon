class Solution {
    public static boolean[] visited;
    public static int[][] computerss;
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[computers.length];
        computerss = computers;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                answer++;
                dfs(i);
            }
        }
        
        return answer;
    }
    
    public void dfs(int index) {
        visited[index] = true;
        int[] currentMap = computerss[index];
        
        for(int i=0;i<currentMap.length;i++) {
            if(i != index && !visited[i] && currentMap[i] == 1) {
                dfs(i);
            }
        }
    }
}
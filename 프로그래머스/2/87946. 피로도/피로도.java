class Solution {
    public static int maxValue = 0;
    public static boolean[] visited;
    public int solution(int k, int[][] dungeons) {
        visited = new boolean[dungeons.length];
        
        dfs(k, 0, dungeons);
        
        return maxValue;
    }
    
    public void dfs(int tired, int depth, int[][] dungeons) {
        maxValue = Math.max(maxValue, depth);
        
        for(int i=0;i<dungeons.length;i++) {
            int[] targetDungeon = dungeons[i];
            int needTired = targetDungeon[0];
            int subTired = targetDungeon[1];
            if(!visited[i] && tired >= needTired) {
                visited[i] = true;
                dfs(tired - subTired, depth+1, dungeons);
                visited[i] = false;
            }
        }
        maxValue = Math.max(depth, maxValue);
    }
}
import java.util.*;
import java.io.*;

public class 효율적인해킹_1325 {//이거 자바 dfs로 풀면 시간초과 남...ㅠ
   
   static int n;//노드 개수
   static ArrayList<Integer> graph[];//인접리스트
   static boolean visited[];//노드 방문여부 체크
   static int cnt = 0;//해킹 가능한 컴퓨터 수

   static void dfs(int cur) {
      visited[cur] = true;//방문 처리
      cnt++;//해킹된 컴퓨터수 카운트
      for(int next : graph[cur]) {//현재노드의 인접노드를 탐색하면서
         if(!visited[next]) {//인접노드에 방문한적이 없으면
            dfs(next);//방문
         }
      }
   }

   public static void main(String[] args) throws IOException {

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      n = Integer.parseInt(st.nextToken());
      int m = Integer.parseInt(st.nextToken());
      
       graph = new ArrayList[n];
       visited = new boolean[n];
       
      //그래프 생성
      for(int i=0; i<n; i++) {
         graph[i] = new ArrayList<Integer>();
      }
      
      //그래프 입력
      for(int i=0; i<m; i++) {
         st = new StringTokenizer(br.readLine());
         int a = Integer.parseInt(st.nextToken())-1;
         int b = Integer.parseInt(st.nextToken())-1;
         graph[b].add(a);//b를 해킹하면 a를 해킹할 수 있음.
      }

      //풀이: 모든 노드에 대해 dfs 수행
      int max = 0;
      int arr[] = new int[n];
      for(int i=0; i<n; i++) {
         cnt = 0;
         visited = new boolean[n];
         dfs(i);
         arr[i] = cnt;
         if(max < cnt) {
            max = cnt;
         }
      }
      
      for(int i=0; i<n; i++) {
         if(arr[i ] == max) {
            bw.append((i+1)+" ");
         }
      }
      
      bw.flush();
      bw.close();
      br.close();
   }

}
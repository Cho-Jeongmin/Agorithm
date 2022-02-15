import java.util.*;
import java.io.*;

public class ȿ��������ŷ_1325 {//�̰� �ڹ� dfs�� Ǯ�� �ð��ʰ� ��...��
   
   static int n;//��� ����
   static ArrayList<Integer> graph[];//��������Ʈ
   static boolean visited[];//��� �湮���� üũ
   static int cnt = 0;//��ŷ ������ ��ǻ�� ��

   static void dfs(int cur) {
      visited[cur] = true;//�湮 ó��
      cnt++;//��ŷ�� ��ǻ�ͼ� ī��Ʈ
      for(int next : graph[cur]) {//�������� ������带 Ž���ϸ鼭
         if(!visited[next]) {//������忡 �湮������ ������
            dfs(next);//�湮
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
       
      //�׷��� ����
      for(int i=0; i<n; i++) {
         graph[i] = new ArrayList<Integer>();
      }
      
      //�׷��� �Է�
      for(int i=0; i<m; i++) {
         st = new StringTokenizer(br.readLine());
         int a = Integer.parseInt(st.nextToken())-1;
         int b = Integer.parseInt(st.nextToken())-1;
         graph[b].add(a);//b�� ��ŷ�ϸ� a�� ��ŷ�� �� ����.
      }

      //Ǯ��: ��� ��忡 ���� dfs ����
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
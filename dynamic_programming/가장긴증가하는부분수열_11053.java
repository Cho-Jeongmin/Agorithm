import java.util.*;
import java.io.*;

public class 가장긴증가하는부분수열_11053 {//LIS(최장증가부분수열 문제)

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		int input[] = new int[n];
		
		st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<n; i++) {
			input[i] = Integer.parseInt(st.nextToken());
		}
		
		//풀이
		int dp[] = new int[n];//dp[i]: 0~i번째 수로만 이루어진 LIS의 길이
		
		for(int i=0; i<n; i++) {
			dp[i] = 1;//초기화.(가장 작은 부분수열의 길이는 항상 1)

			for(int j=0; j<i; j++) {//i보다 앞에 있는 수들 중
				if(input[j] < input[i]) { //i번째 수보다 더 작은 j번째 수에 대해
					dp[i] = Math.max(dp[i], dp[j]+1); //기존 dp[i]값과 dp[j]+1중 더 큰값으로 갱신
				}
			}
		}
		
		//dp중 최댓값 찾기
		int max = 0;
		for(int i=0; i<n; i++) {
			max = Math.max(max, dp[i]);
		}
		
		System.out.println(max);
	}

}

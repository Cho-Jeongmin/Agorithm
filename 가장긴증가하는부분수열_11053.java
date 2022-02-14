import java.util.*;
import java.io.*;

public class ����������ϴºκм���_11053 {//LIS(���������κм��� ����)

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		int input[] = new int[n];
		
		st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<n; i++) {
			input[i] = Integer.parseInt(st.nextToken());
		}
		
		//Ǯ��
		int dp[] = new int[n];//dp[i]: 0~i��° ���θ� �̷���� LIS�� ����
		
		for(int i=0; i<n; i++) {
			dp[i] = 1;//�ʱ�ȭ.(���� ���� �κм����� ���̴� �׻� 1)

			for(int j=0; j<i; j++) {//i���� �տ� �ִ� ���� ��
				if(input[j] < input[i]) { //i��° ������ �� ���� j��° ���� ����
					dp[i] = Math.max(dp[i], dp[j]+1); //���� dp[i]���� dp[j]+1�� �� ū������ ����
				}
			}
		}
		
		//dp�� �ִ� ã��
		int max = 0;
		for(int i=0; i<n; i++) {
			max = Math.max(max, dp[i]);
		}
		
		System.out.println(max);
	}

}

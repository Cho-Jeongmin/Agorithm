import java.util.*;

public class 동전0_11047 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		int a[] = new int[n];
		
		for(int i=0; i<n; i++) {
			a[i] = sc.nextInt();
		}
		
		int cnt = 0;
		
		for(int i=n-1; i>=0; i--) {
			cnt += k/a[i];//몫
			k = k%a[i];//나머지
		}
		
		System.out.println(cnt);
	}

}

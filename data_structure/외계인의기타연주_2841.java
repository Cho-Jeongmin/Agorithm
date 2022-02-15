import java.util.*;
import java.io.*;

public class ¿Ü°èÀÎÀÇ±âÅ¸¿¬ÁÖ_2841 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		
		Stack<Integer> stack[] = new Stack[n];
		for(int i=0; i<n; i++) {
			stack[i] = new Stack<Integer>();
		}
		
		int cnt = 0;
		
		while(n-->0) {
			st = new StringTokenizer(br.readLine());
			
			int line = Integer.parseInt(st.nextToken());
			int fret = Integer.parseInt(st.nextToken());
			
			while(!stack[line].isEmpty() && stack[line].peek() > fret) {
				stack[line].pop();
				cnt++;
			}
			
			if(stack[line].isEmpty() || stack[line].peek() < fret) {
				stack[line].push(fret);
				cnt++;
			}
			
		}
		
		System.out.println(cnt);
		
	}
}

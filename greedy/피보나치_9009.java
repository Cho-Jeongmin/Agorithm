import java.io.*;
import java.util.*;;

public class 피보나치_9009 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		
		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			
			//피보나치 수열 구하기 (n보다 작은 수까지만)
			ArrayList<Integer> fivo = new ArrayList<Integer>();
			fivo.add(0);
			fivo.add(1);
			int i = 2;
			while(true) {
				int tmp = fivo.get(i-1) + fivo.get(i-2);
				if(tmp > n) break;
				fivo.add(tmp);
				i++;
			}
			
			ArrayList<Integer> ans = new ArrayList<Integer>();
			
			//피보나치 수열에서 큰수부터 n에서 빼주기
			while(n != 0) {
				for(int j=fivo.size()-1; j>=0; j--) {
					if(fivo.get(j) <= n) {
						n -= fivo.get(j);
						bw.write(ans.get(j)+" ");
					}
				}
			}
			
			Collections.sort(ans);
			for(int j=1; j<ans.size(); j++) {
				bw.write(ans.get(j)+" ");
			}
			bw.write("\n");
		}
		
		bw.flush();
		bw.close();
		br.close();

	}

}

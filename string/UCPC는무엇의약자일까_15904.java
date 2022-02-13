import java.io.*;

public class UCPC는무엇의약자일까_15904 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char ucpc[] = {'U', 'C', 'P', 'C'};
		
		String s = br.readLine();
		int index = 0;
		boolean success = false;
		
		for(int i=0; i<s.length(); i++) {
			if(s.charAt(i) == ucpc[index]) {
				if(index==3) {
					success = true; break;
				}
				else index++;
			}
		}
		
		if(success) System.out.println("I love UCPC");
		else System.out.println("I hate UCPC");

	}

}

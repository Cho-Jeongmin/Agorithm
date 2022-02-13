import java.io.*;
import java.util.*;

public class 거울상_4583 {

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		HashSet<Character> mirror = new HashSet<>(Arrays.asList('i', 'o', 'v', 'w', 'x'));
		
		String s = sc.nextLine();
		
		while(!s.contentEquals("#")) {
			
			
			boolean valid = true;
			String ans = "";
			for(int i=0; i<s.length(); i++) {
				
				char ch = s.charAt(i);
				
				if(ch=='b') ans = 'd'+ans;
				else if(ch=='d') ans = 'b'+ans;
				else if(ch=='p') ans = 'q'+ans;
				else if(ch=='q') ans = 'p'+ans;
				else if(mirror.contains(ch)) ans = ch+ans;
				else {//거울상 문자가 아닐 경우
					valid = false;
					break;
				}
			}
			
			if(!valid) ans = "INVALID";
			
			bw.append(ans+"\n");
			
			s = sc.nextLine();
		}
		
		bw.flush();
		bw.close();
		
	}

}

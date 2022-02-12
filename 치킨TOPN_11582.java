import java.io.*;
import java.util.*;

public class 치킨TOPN_11582 {
	
	static int arr[];
	static int tmp[];
	static int n, k;
	
	//합병 함수 (두개의 정렬된 부분배열을 하나의 정렬된 배열로 합치기)
	static void merge(int start, int end) {
		
		if((end-start+1) > (n/k)) return;
		//현재 정렬중인 부분배열의 크기가 k명이 정렬할때의 부분배열의 크기보다 크다면, 정렬하지 않고 그대로 리턴
		
		int mid = (start+end)/2;
		
		int k = 0;//tmp배열의 포인터
		int i = start;//왼쪽 부분배열 포인터
		int j = mid+1;//오른쪽 부분배열 포인터
		
		while(i<=mid && j<=end) {
			if(arr[i] < arr[j]) tmp[k++] = arr[i++];
			else tmp[k++] = arr[j++];
		}
		
		while(i<=mid) tmp[k++] = arr[i++];
		while(j<=end) tmp[k++] = arr[j++];
		
		k=0;
		for(i=start; i<=end; i++) arr[i] = tmp[k++];
	}
	
	//합병 정렬 함수
	static void mergeSort(int start, int end) {
		
		if(start==end) return;	//종료조건 : 배열 길이가 1
		
		int mid = (start+end)/2;
		
		mergeSort(start, mid);	//왼쪽 부분배열 정렬
		mergeSort(mid+1, end);	//오른쪽 부분배열 정렬
		
		merge(start, end);	//두 부분배열을 합치기

	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		
		arr = new int[n];
		tmp = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		k = Integer.parseInt(br.readLine());
		
		mergeSort(0, n-1);
		
		for(int i=0; i<n; i++) {
			System.out.print(arr[i]+" ");
		}
		
	}

}

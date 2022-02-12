import java.io.*;
import java.util.*;

public class ġŲTOPN_11582 {
	
	static int arr[];
	static int tmp[];
	static int n, k;
	
	//�պ� �Լ� (�ΰ��� ���ĵ� �κй迭�� �ϳ��� ���ĵ� �迭�� ��ġ��)
	static void merge(int start, int end) {
		
		if((end-start+1) > (n/k)) return;
		//���� �������� �κй迭�� ũ�Ⱑ k���� �����Ҷ��� �κй迭�� ũ�⺸�� ũ�ٸ�, �������� �ʰ� �״�� ����
		
		int mid = (start+end)/2;
		
		int k = 0;//tmp�迭�� ������
		int i = start;//���� �κй迭 ������
		int j = mid+1;//������ �κй迭 ������
		
		while(i<=mid && j<=end) {
			if(arr[i] < arr[j]) tmp[k++] = arr[i++];
			else tmp[k++] = arr[j++];
		}
		
		while(i<=mid) tmp[k++] = arr[i++];
		while(j<=end) tmp[k++] = arr[j++];
		
		k=0;
		for(i=start; i<=end; i++) arr[i] = tmp[k++];
	}
	
	//�պ� ���� �Լ�
	static void mergeSort(int start, int end) {
		
		if(start==end) return;	//�������� : �迭 ���̰� 1
		
		int mid = (start+end)/2;
		
		mergeSort(start, mid);	//���� �κй迭 ����
		mergeSort(mid+1, end);	//������ �κй迭 ����
		
		merge(start, end);	//�� �κй迭�� ��ġ��

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

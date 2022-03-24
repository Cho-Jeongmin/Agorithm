#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {

	if (a.length() != b.length()) {//���ڿ� ���̰� �ٸ���
		return a.length() < b.length();
	}
	else {//���ڿ� ���̰� ������
		int len = a.length();
		int sum1 = 0, sum2 = 0;//�ڸ����� ��
		for (int i = 0; i < len; i++) {
			if (a[i] >= '0' && a[i] <= '9') sum1 += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') sum2 += b[i] - '0';
		}
		if (sum1 != sum2) {//�ڸ����� ���� �ٸ���
			return sum1 < sum2;
		}
		else {//�ڸ����� ���� ������
			return a < b;
		}
	}
	
}

int main(void) {

	int N;
	string serial[51];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}

	sort(serial, serial+N, compare);

	for (int i = 0; i < N; i++) {
		cout << serial[i] << endl;
	}

	return 0;
}
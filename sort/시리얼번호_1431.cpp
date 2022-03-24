#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {

	if (a.length() != b.length()) {//문자열 길이가 다르면
		return a.length() < b.length();
	}
	else {//문자열 길이가 같으면
		int len = a.length();
		int sum1 = 0, sum2 = 0;//자리수의 합
		for (int i = 0; i < len; i++) {
			if (a[i] >= '0' && a[i] <= '9') sum1 += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') sum2 += b[i] - '0';
		}
		if (sum1 != sum2) {//자리수의 합이 다르면
			return sum1 < sum2;
		}
		else {//자리수의 합이 같으면
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
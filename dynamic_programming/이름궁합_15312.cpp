#include <iostream>
#include <vector>

using namespace std;

int stroke[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main(void) {

	string a, b;

	cin >> a >> b;

	vector<int> v;

	for (int i = 0; i < a.length(); i++) {
		v.push_back(stroke[a[i] - 'A']);
		v.push_back(stroke[b[i] - 'A']);
	}

	while (v.size() > 2) {//두자릿수가 될때까지
		for (int j = 0; j < v.size() - 1; j++) {//원소들을 훑으면서
			v[j] = (v[j] + v[j + 1])%10;//인접한 두 원소의 합의 일의자리수
		}
		v.erase(v.begin() + v.size()-1);//마지막 원소 삭제
	}

	cout << v[0] << v[1] << endl;

	return 0;
}
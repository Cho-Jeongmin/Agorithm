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

	while (v.size() > 2) {//���ڸ����� �ɶ�����
		for (int j = 0; j < v.size() - 1; j++) {//���ҵ��� �����鼭
			v[j] = (v[j] + v[j + 1])%10;//������ �� ������ ���� �����ڸ���
		}
		v.erase(v.begin() + v.size()-1);//������ ���� ����
	}

	cout << v[0] << v[1] << endl;

	return 0;
}
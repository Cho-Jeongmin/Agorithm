#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solution(int n, vector<string>words) {

	int answer = 0;

    int alp1[26] = { 0, };

    //���ع��ڿ��� �� ���ĺ� ���� ����
    for (int i = 0; i < words[0].length(); i++) {
        alp1[words[0][i] - 'A']++;
    }

    for (int i = 1; i < n; i++) {
        int alp2[26] = { 0, };

        //���� ���ڿ��� �� ���ĺ� ���� ����
        for (int j = 0; j < words[i].length(); j++) {
            alp2[words[i][j] - 'A']++;
        }

        bool fail = false;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for (int j = 0; j < 26; j++) {
            if (abs(alp1[j] - alp2[j]) >= 2) {//2�� �̻� ����
                fail = true;
                break;
            }
            if (alp1[j] > alp2[j]) cnt1++;
            if (alp1[j] < alp2[j]) cnt2++;
            if (cnt1 >= 2 || cnt2 >= 2) {//������ �ٸ� ���ĺ��� 2�� �̻��̸�
                fail = true;
                break;
            }
        }
        if (!fail) answer++;
    }

	return answer;
}

int main(void) {
    int n, i;

    int answer = 0;

    cin >> n;
    vector<string> words(n);
    for (i = 0; i < n; i++)
        cin >> words[i];

    answer = solution(n, words);
    cout << answer;
}
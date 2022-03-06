#include <iostream>
#include <vector>
#define INF 30000000

using namespace std;

struct edge {//���� ����ü
	int s, e, t;
};

int tc, n, m, w;
vector<edge> edges;//���� �迭
int dist[501];//�ִܰŸ�

bool bellman_ford(int start) {//�������� �˰���

	dist[start] = 0;

	for (int i = 1; i <= n; i++) {//n�� �ݺ�

		for (int j = 0; j < edges.size(); j++) {//���� ������ŭ �ݺ�

			int s, e, t;
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;

			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
				if (i == n) {//n��° �ݺ��� ���� ������ �Ͼ���Ƿ�
					return true;//���� ����Ŭ ����
				}
			}
		}
	}

	return false;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	while (tc-- > 0) {

		cin >> n >> m >> w;

		edges.clear();//�ʱ�ȭ

		int s, e, t;

		//���� ���� �Է�(�����)
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s, e, t });
			edges.push_back({ e, s, t });
		}

		//��Ȧ ���� �Է�(�ܹ���)
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s, e, -t });
		}

		//dist �ʱ�ȭ
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}

		if (bellman_ford(1)) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}
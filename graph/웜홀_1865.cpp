#include <iostream>
#include <vector>
#define INF 30000000

using namespace std;

struct edge {//간선 구조체
	int s, e, t;
};

int tc, n, m, w;
vector<edge> edges;//간선 배열
int dist[501];//최단거리

bool bellman_ford(int start) {//벨만포드 알고리즘

	dist[start] = 0;

	for (int i = 1; i <= n; i++) {//n번 반복

		for (int j = 0; j < edges.size(); j++) {//간선 개수만큼 반복

			int s, e, t;
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;

			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
				if (i == n) {//n번째 반복할 때도 갱신이 일어났으므로
					return true;//음의 사이클 존재
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

		edges.clear();//초기화

		int s, e, t;

		//도로 정보 입력(양방향)
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s, e, t });
			edges.push_back({ e, s, t });
		}

		//웜홀 정보 입력(단방향)
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s, e, -t });
		}

		//dist 초기화
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}

		if (bellman_ford(1)) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}
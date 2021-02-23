#include <bits/stdc++.h>

using namespace std;
int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
ifstream fin("input.in");

void solve() {
	long long int X, Y, startx, starty, N;
	fin >> X >> Y >> startx >> starty >> N;
	pair<pair<int, int>, pair<int, int> > portal[N + 5];
	bool vis[N + 5];

	for (int i = 0; i < N; i++) {
		vis[i] = false;
		fin >> portal[i].first.first >> portal[i].first.second
				>> portal[i].second.first >> portal[i].second.second;
	}
//	sort(portal, portal + N);
	long long posx = startx;
	long long posy = starty;
	long long moves = 0;
	while (true) {
		long long min = 1000000000000;
		long long port = 0;
		bool used = true;
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				long long d = dist(posx, posy, portal[i].first.first,
						portal[i].first.second);
				if (d < min) {
					used = false;

					port = i;
					min = d;

				} else if (d == min) {
					if (portal[i].first.first < portal[port].first.first) {
						used = false;
						port = i;
						min = d;
					} else if (portal[i].first.first == portal[port].first.first) {
						if (portal[i].first.second < portal[port].first.second) {
							used = false;
							port = i;
							min = d;
						}
					}
				}
			}
		}
		if (used) {
			break;
		}
		moves = (moves + min)%100003;
        posx = portal[port].second.first;
        posy = portal[port].second.second;
		vis[port] = true;

	}
	moves = moves % 100003;
	cout << moves % 100003 << endl;
//	if (moves > 100003) cout <<" what "<<endl;
}

int main() {
	int T;
	fin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
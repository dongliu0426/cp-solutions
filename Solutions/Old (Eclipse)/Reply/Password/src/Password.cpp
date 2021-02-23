#include <bits/stdc++.h>
using namespace std;

// structures and defines
#define MOD 1000000007
// global variables

ifstream fin ("input.in");

// functions
int computeK(string pat, int M) {
	int len = 0;

	int lps[M];
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps[M-1];
}
bool check(string str) {
	int val = -1;
	for (int i=0; i<str.size(); i++) {
		if (val == -1) {
			val = str[i];
		} else if (val != str[i]) {
			return false;
		}
	}
	return true;
}
void solve(int t) {
	int N, M; string S;
	fin >> N >> M >> S;
	long long ans;
	if (M > N) {
		ans = (1<<N)%MOD;
	} else {
		int K = computeK(S, M);
		int X=(N-M), Y=0;
		ans = (1<<N);
		cout<<"K: " << K<<endl;
		if (K == 0) K = MOD;
		for (int i=1; i<=(N-M+1); i++, X--, Y++) {
			long long sum;
			if (Y < K) {
				sum = (1<<X)*(1<<Y);
			} else {
				sum = (1<<X)*((1<<(M-K))-1)*(1<<(Y-K));
			}
			cout<<X<<" "<<Y<<" -> " << ans << " s: "<<sum<<endl;
			ans -= sum;
		}

	}
	cout<< "Case #"<<t<<": " << ans << endl;
}

int main() {
	// local variables
	int T;

	// input
	fin >> T;

	// main
	for (int i=1; i<=T; i++) solve(i);
	// output

	return 0;
}
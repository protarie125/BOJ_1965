#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vi box;
vi dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	box = vi(n + 1, 0);
	dp = vi(n + 1, 0);
	for (auto i = 1; i <= n; ++i) {
		cin >> box[i];
	}

	auto ans = int{ 0 };
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 0; j < i; ++j) {
			if (box[j] < box[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}
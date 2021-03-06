/*
	BOJ1912
	<연속합>
	문제
	n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	vector <int> v(n + 1);
	vector <int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {//값 초기화
		cin >> v[i];
		dp[i] = v[i];
	}
	int ans = dp[0] = -9999999;
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + v[i]);
		ans = max(dp[i],ans);
	}
	cout << ans;
	return 0;
}

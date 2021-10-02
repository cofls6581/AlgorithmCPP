/*
	BOJ15657
	<N과 M (8)>
	문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int num[9];
bool check[9];
int N, M;

void dfs(int n ,int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = n; i <= N; i++) {
		check[i] = true;
		arr[cnt] = num[i - 1];
		dfs(i,cnt + 1);
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	dfs(1,0);
}

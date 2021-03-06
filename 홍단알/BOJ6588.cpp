/*
	BOJ6588
	<골드바흐의 추측>
	문제
	1742년, 독일의 아마추어 수학가 크리스티안 골드바흐는 레온하르트 오일러에게 다음과 같은 추측을 제안하는 편지를 보냈다.

4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
예를 들어 8은 3 + 5로 나타낼 수 있고, 3과 5는 모두 홀수인 소수이다. 또, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 이다.

이 추측은 아직도 해결되지 않은 문제이다.

백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오.
*/

#include <iostream>
#define max 1000000 
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(0);
	bool check[max + 1] = {false, };
	check[0] = check[1]= check[2] = true;

	for (int i = 2; i <= max; ++i) {
		if (check[i] == false) {
			for (int j = i+i ; j <= max ; j+=i)
				check[j] = true;
		}
	}

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 2; i <= n/2; i++) {
			if ((check[i] == false) && (check[n - i] == false)) {
				cout << n << " = " << i << " + " << (n - i)<<'\n';
				break;
			}
		}
	}
	return 0;
}

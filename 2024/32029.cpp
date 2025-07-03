#include <iostream>
#include <algorithm>

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n, a, b;
	std::cin >> n >> a >> b;

	int list[101] = { };
	for (int i{ 0 }; i < n; i++) {
		std::cin >> list[i];
	}

	std::sort(list, list + n);

	int ans = 0;
	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < a; j++) {
			int t = 0;
			int m = a;
			int res = 0;
			for (int k{ 0 }; k < n; k++) {
				if (k == i) {
					t += j * b;
					m -= j;
				}

				t += m;
				if (t <= list[k]) {
					res++;
				}
				else {
					t -= m;
				}
			}

			ans = std::max(res, ans);
		}
	}

	std::cout << ans << "\n";
}

//문제 풀이
//
//설정해야 하는 조건들은
//1. 잠을 자는 타이밍
//2. 잠을 자는 시간
//3. 정렬 순 대로 진행되지 않을 흐름
//
//1. 잠을 자는 타이밍
//잠을 잘 필요가 있는 경우 -> 과제 n개가 남았을 때, B가 n개 보다 커야어야 한다.
//
//2. 잠을 자는 시간
//정확히 구하는 것 보다 모든 A에 대해 for문을 돌리는 것이 효율적이다.
//
//3. 정렬 순 대로 진행되지 않을 흐름
//오름차순으로 정렬을 해도 i 과제를 수행하지 못해도 i + n, i + n + 1 , ... 의 여러 과제를 수행할 확률이 존재한다.
//따라서 for 문을 끝까지 돌린다.
//
//N이 100임을 고려해서 3중 for문으로 해결한다.

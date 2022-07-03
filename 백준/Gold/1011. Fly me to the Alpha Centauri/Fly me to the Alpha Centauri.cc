#include <iostream>
#include <algorithm>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

	// x, y의 절대적 위치보다 둘의 거리가 중요하다.
	// 당연하지만 최단 시간에 가려면 평균 속도가 높아야한다.
	// 속도는 1에서 시작해서 1로 끝난다. 가속도는 -1, 0, 1 중 하나. 평균 속도를 높히려면,
	// 속도를 최대한 높혀서 최고점을 찍고 다시 내려오는 형식으로 해야한다.
	// 즉, 속도-시간 그래프가 최고점을 찍는 시간을 축으로 하는 대칭 모양이다.
	//	대칭을 이용하여 풀자.




int countRunning(int dis) { // dis는 남은 거리

	int velo = 1;		// velo는 현재 속도
	int count = 0;
	int flag = 0;

	while (dis >= velo) {   // 남은 거리가 현재 속도보다 크거나 같으면 한 턴 더 갈 수 있음.
		dis -= velo;		// 한 턴 간걸로 치고 속도만큼 뺸다.
		count++;			// 작동했으니까 count

		if (dis == 0) flag = 1; // 만약 남은 거리가 없다면? 다 온거다. flag = 1 해주자.
		if (dis < velo) break;	// 현재 속도가 남은 거리보다 크면, 더 갈 수 없다. 속도를 낮춰야함.
		
		dis -= velo;
		count++;				
		if (dis == 0) flag = 1;	// 대칭 이용하기. 
								// 최고 속도보다 작은 속도로 한 번 갔으면, 적어도 한 번은 더 그 속도로 간다.
								// ex. 속도 : 1 -> 2 -> 3 -> 2 -> 1 왜냐하면 속도는 다시 1로 돌아와야하니까.

		velo++; // 대칭 끝났으면 속도 올려주기.
	}

	if (flag == 0) count++;  // 만약 위의 대칭에서 dis, 즉 거리가 0이 아니라면 현재 속도보다 작은 거리가 남았다는 뜻이다.
							// 근데 위의 반복문이 끝난 시점에서 현재 속도는 최고 속도이다. 최고 속도보다 작은 자연수의 속도는 항상 존재하므로
							// 그 속도만큼 한 번 더 가주면 된다. 따라서 count++, 만약 dis가 0이면 더 갈 필요가 없다.
	
	return count;

}



int main() {
	
	int T;
	int x, y;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> T;


	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		cout << countRunning(y - x) << "\n";
	}

}
//못풀어서 책참조...
/*
cache[i][j]는 A에서 i, B에서 j부터 시작하는 두 증가부분수열의 JLIS값을 저장한다.

최대 증가 부분수열은 [최소값1, 최소값2, ....]로 시작한다.
즉, 기본값이 2개를 넣고 하기 때문에 ret가 2가 나온다.
그래서 메인에서 -2를 해줘야 원래의 값이 나오게 된다.

max(a,b)로 비교하는 이유는, 중복된 값 (a에서 4 , b에서 4)자체를 들어가지 않고 계산하기 위함

생각하는 깊이를 키우자....





*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long UNDEFINED = std::numeric_limits<long long>::min();

int A_sequence[101], B_sequence[101];
int cache[101][101];      //cache[i][j] : A에서 i부터 시작하는 수열과, B에서 j부터 시작하는 수열의 JLIS값 저장.

void init(int N, int M)
{
	//A관련 값 초기화
	for (int i = 0; i < N; i++) {
		cin >> A_sequence[i];

	}
	//B관련 값 초기화
	for (int i = 0; i < M; i++) {
		cin >> B_sequence[i];

	}
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			cache[i][j] = -1;

}

int JLIS(int A_idx, int B_idx, int N, int M)
{
	int & ret = cache[A_idx + 1][B_idx + 1];

	if (ret != -1)
		return ret;

	ret = 2;
	long long a = (A_idx == -1 ? UNDEFINED : A_sequence[A_idx]);
	long long b = (B_idx == -1 ? UNDEFINED : B_sequence[B_idx]);
	long long maxElement = max(a, b);

	for (int i = A_idx + 1; i < N; i++)
		if (maxElement < A_sequence[i])
			ret = max(ret, JLIS(i, B_idx, N, M)+1);

	for (int i = B_idx + 1; i < M; i++)
		if (maxElement < B_sequence[i])
			ret = max(ret, JLIS(A_idx, i, N, M) + 1);
	return ret;

}





int main()
{

	int C;
	cin >> C;
	while (C--)
	{
		
		int N, M; //A,B길이
		cin >> N >> M;
		init(N, M);
		cout << JLIS(-1, -1, N, M) -2 << endl;
		



	}

	return 0;
}






























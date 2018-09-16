/*-------------
18.9.16 JLIS with DP
JMBook p239 참조.
아직 혼자 풀기 힘들다


-------------*/

#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

const long long UNDEFINED = std::numeric_limits<long long>::min(); 

//int cache[100][100]; //idxA에서 시작하는 부분수열과 idxB에서 시작하는 부분수열에서 가장 긴 jlis값을 cache[idxA][idxB]에 저장
						   //-1로 초기화

int cache[101][101];
int n, m;
int A[100], B[100];

int jlis2(int indexA, int indexB)
{
	int & ret = cache[indexA+1][indexB+1];
	if(ret !=-1) return ret;
	
	ret = 2;
	long long a = (indexA == -1 ? UNDEFINED : A[indexA]);
	long long b = (indexB == -1 ? UNDEFINED : B[indexB]);
	long long maxElement = max(a,b);
	
	for(int nextA = indexA +1; nextA <n; ++nextA)
	{
		if(maxElement < A[nextA])
			ret = max(ret, jlis2(nextA, indexB) +1);
		
	}
	for(int nextB = indexB+1; nextB < m; ++nextB)
	{
		if(maxElement < B[nextB])
			ret = max(ret, jlis2(indexA, nextB) +1);
	}
	
	return ret;
}



int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		cin>>n>>m;
		for(int i= 0 ; i<n; i++)
		{
			cin>>A[i];
		}
		for(int i = 0 ; i<m; i++)
		{
			cin>>B[i];
		}
		
		for(int i = 0 ; i<=n; i++)
			for(int j = 0 ; j<=m; j++)
				cache[i][j] = -1;
		

	cout<<jlis2(-1,-1)-2<<endl;
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}













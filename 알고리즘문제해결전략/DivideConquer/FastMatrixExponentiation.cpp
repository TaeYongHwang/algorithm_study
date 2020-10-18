#include <iostream>
#include <vector>
using namespace std;
//A^p 계산 , 각 원소는 10007에 대한 나머지를 계산
//행렬의 거듭제곱
class SquareMatrix
{
private:
	vector<vector<long long> > v;
public:
	SquareMatrix(int n)
		:v(n, vector<long long>(n, 0)) {}
	
	void Init(int y, int x, long long value)  //y행x열에 value값 넣기
	{
		v[y][x] = value;
		
	}
	int getSize()
		{ return v.size() ;}
	long long getValue(int y, int x) { return v[y][x];}
	
	friend SquareMatrix operator*(SquareMatrix &A, SquareMatrix &B);
	friend SquareMatrix identity(int);
};

SquareMatrix operator*(SquareMatrix &A, SquareMatrix &B)
{
	int size = A.v.size();
	long long sum = 0;
	SquareMatrix temMat(size);
	for(int i =0 ; i<size; i++)
	{
	
		for(int j = 0 ; j<size; j++)
		{
			for(int k = 0 ; k<size; k++)
				sum+= (A.v[i][k]* B.v[k][j]);
			
			sum%=10007;
			temMat.v[i][j] = sum;
			sum = 0;
			
		}
		
	}

	return temMat;
	
}

SquareMatrix identity(int n)
{
	SquareMatrix tem(n);
	
	for(int i = 0 ; i<n; i++)
		for(int j = 0 ; j<n; j++)
			if(i==j)
				tem.v[i][j] =1;
	
	return tem;
	
}


SquareMatrix MatExponentiation(int n, SquareMatrix& mat)
{
	
	if(n == 0)
		return identity(mat.getSize());
	
	if(n%2 == 1) //홀수인경우
	{
		SquareMatrix temp  = MatExponentiation(n-1, mat);
		return temp*mat;
		
	}
	
	SquareMatrix half = MatExponentiation(n/2, mat);
	return half*half;
	
	
}

int main()
{
	int C;
	int N,p;
	cin>>C;
	while(C>0)
	{
		cin>>N>>p;
		SquareMatrix X(N);
		
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				long long temp;
				cin>>temp;
				X.Init(i,j,temp);
				
			}
		}
		
		SquareMatrix tem = MatExponentiation(p,X);
				
		
		for(int i = 0 ; i<tem.getSize(); i++)
		{
			for(int j =0; j<tem.getSize(); j++)
			{
				cout<<tem.getValue(i,j)<<' ';
			}
			cout<<endl;
		}
		
		
		
		
		
		
		
		
		
		
		C--;
	}
	


	
	return 0;
	
}






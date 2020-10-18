//알고리즘 문제해결전략 203p (내 실력에는 너무 어려운 문제..) 책참조

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//알고리즘 문제해결전락 p 184;

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//자리의 올림 처리
void normalize(vector<int>& num)
{
	num.push_back(0);
	
	for(int i = 0 ; i< num.size(); i++)
	{
		if(num[i] <0){
			int borrow = ( (abs(num[i])+9) /10);
			num[i+1] -=borrow;
			num[i]%=10;
		}
		else{
			num[i+1] +=num[i] / 10;
			num[i] %= 10;
		}
	}
	
	while(num.size() > 1 &&num.back() == 0) num.pop_back();
	
	
}

vector<int> multiply(const vector<int>&a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() +1, 0);
	for(int i = 0 ; i<a.size(); i++)
		for(int j = 0 ; j<b.size(); j++)
			c[i+j] += a[i] * b[j];
	
	return c;
}



//p187
//카라츠바의 빠른 정수 곱셈 알고리즘
void addTo(vector<int>& a,vector<int>& b, int k)
{
    a.resize(max(a.size(), b.size()+k));
    for(int i = 0; i < b.size(); i++)
    {
        a[i+k]+=b[i];

    }
}
void subFrom(vector<int>& a,vector<int>&b)
{
    for(int i = 0; i < b.size(); i++)
    {
        a[i]-=b[i];
    }
}
vector<int> karatsuba(const vector<int>&a, const vector<int>&b)
{
	int an = a.size(), bn = b.size();
	//a가 b보다 짧을 경우 둘을 바꿈
	if(an<bn) return karatsuba(b,a);
	
	//basecase : a나 b가 비어있는 경우
	if(an == 0 || bn == 0) return vector<int>();
	
	//basecase : a가 비교적 짧은 경우 O(n^2)곱셈으로 변경한다.
	if(an<=50) return multiply(a,b);
	int half = an/2;
	
	//a 와 b를 밑에서 half자리와 나머지로 분리
	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin()+ min<int>(b.size(), half));
	vector<int> b1(b.begin() +min<int>(b.size(), half), b.end());
	
	//z2 = a1*b1;
	vector<int> z2 = karatsuba(a1,b1);
	//z0 = a0*b0;
	vector<int> z0 = karatsuba(a0,b0);
	//a0 = a0+a1; b0 = b0+b1
	addTo(a0,a1,0); addTo(b0,b1,0);
	//z1 = (a0*b0) -z0-z2
	vector<int> z1= karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);
	//ret = z0 + z1 * 10^half + z2 * 10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret,z2,half+half);
	return ret;
	
	
	
	
	
	
	
}



int hugs(const string& members, const string& fans)
{
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for(int i = 0 ; i<N; i++) A[i] = (members[i]=='M');
	for(int i = 0 ; i<M; i++) B[i] = (fans[i] =='M');
	//카라츠바알고리즘에서 자리올림 생략
	vector<int> C = karatsuba(A,B);
	int allHugs = 0 ;
	for(int i = N-1 ; i<M; i++)
		if(C[i] ==0)
			++allHugs;
	return allHugs;
	
}




















int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		string mem;
		string fan;
		
		cin>>mem>>fan;

		reverse(fan.begin(), fan.end());
		
		
		cout<<hugs(mem,fan)<<endl;

		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}


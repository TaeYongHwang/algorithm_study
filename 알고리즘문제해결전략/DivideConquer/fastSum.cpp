#include <iostream>
#include <vector>
using namespace std;
//1...n까지의 합 
int fastSum(int size)
{
	if(size == 1)
		return 1;
	if(size%2 ==1)  //홀수인경우
		return fastSum(size-1)+size;
	

	return 2*fastSum(size/2)+((size*size)/4);
		
	
}






int main()
{
	cout<<fastSum(6);
	
	
	
	
	return 0;
}
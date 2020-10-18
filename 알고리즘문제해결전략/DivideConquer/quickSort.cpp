#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//내림차순정렬

void quickSort(vector<int>& v, int startIdx, int endIdx) //[]
{
	if(startIdx == endIdx)
		return;
	
	int pivot = v[startIdx];
	
	int tempValue;
	int Idx = startIdx;
	vector<int> left;
	vector<int> right;
	
	for(int i = startIdx+1; i<=endIdx; i++)   //모든 값은 pivot과 비교
	{
		if(pivot >= v[i])
			right.push_back(v[i]);	
		else
			left.push_back(v[i]);
		
	}
	
	//값을 다시 채워넣음
	for(int i = 0; i<left.size(); i++)
		v[Idx++] = left[i];
	
	int pivotIdx = Idx;
	v[Idx++] = pivot;
	
	for(int i = 0 ; i<right.size(); i++)
		v[Idx++] = right[i];
	
	vector<int>().swap(left);
	vector<int>().swap(right);
	
	//양쪽 끝에 피봇값이 있는 경우 예외처리
	if(startIdx !=pivotIdx)
		quickSort(v, startIdx, pivotIdx-1);
	
	if(endIdx != pivotIdx)
		quickSort(v, pivotIdx+1, endIdx);
	
}

int main()
{
	srand(time(NULL));
	vector<int> v;
	
	for(int i = 0 ; i <6; i++)
		v.push_back(rand()%100);
	
	
	
	for(int i = 0 ; i<v.size() ; i++)
		cout<<v[i]<<' ';
	cout<< endl;
	

	quickSort(v, 0,v.size()-1 );

	
	for(int i = 0 ; i<v.size() ; i++)
		cout<<v[i]<<' ';
	cout<< endl;
	
	
	
	return 0;
}








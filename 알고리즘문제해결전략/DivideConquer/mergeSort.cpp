#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//내림차순정렬

void mergeSort(vector<int>& V, int start, int end)  //[start,end]
{
	if(start == end) //basecase
	{
		return; 
		
	}
	
	
	int midValue = (start+end+1)/2;
	
	mergeSort(V, start, midValue-1); //절반의 왼쪽으로
	mergeSort(V, midValue, end);     //절반의 오른쪽으로
	
	vector<int> temp;
	temp.assign( V.begin() ,  V.end() );  //전체복사
	int idx = start;
	int leftIdx = start;
	int rithtIdx = midValue;
	
	while( leftIdx<=midValue-1 && rithtIdx<=end) //범위넘어갈경우
	{
		if(temp[leftIdx] >=temp[rithtIdx])
		{
			V[idx++] = temp[leftIdx++];		
			continue;
		}
		else
		{
			V[idx++] = temp[rithtIdx++];
			continue;
		}
		
	}

	while(idx <= end) //비교후 남은 값 마저채우기
	{
		if(leftIdx<=midValue-1)
		{
			V[idx++] = temp[leftIdx++];
			continue;
		}
		else if(rithtIdx <=end )
		{
			V[idx++] = temp[rithtIdx++];
			continue;
		}
		
	}
	
	vector<int>().swap(temp);
	return;

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
	

	mergeSort(v, 0,v.size()-1 );

	
	for(int i = 0 ; i<v.size() ; i++)
		cout<<v[i]<<' ';
	cout<< endl;
	
	
	
	return 0;
}



//무식하게 푸는 법
#include <iostream>
#include <vector>
using namespace std;

#define UNDEFINED -1

//vector<int> height는 0과 N+1 인덱스에 UNDEFINED값이 들어있는 형태, 즉 1~N의 인덱스로 계산함

//해당 인덱스에서 최대직사각형넓이찾는함수
void findMaxRectangle(vector<int>& height, vector<bool>& visit, int idx , int curHeight) 
{
	visit[idx] =true;

	//범위초과 basecase
	if(idx == 0 || idx == height.size()-1)
	{
		return; 
	}
	//더이상 확장이 안될 때 basecase
	if(height[idx]<curHeight)
	{
		visit[idx] = false;
		return;	
	}
		
	//기본적인 경우(height[idx] >=curHeight)
	if(visit[idx-1] ==false)
		findMaxRectangle(height, visit, idx-1, curHeight);
	if(visit[idx+1] == false)
		findMaxRectangle(height, visit, idx+1, curHeight);

}






int main()
{
	int C, N;
	cin>>C;
	
	while(C--)
	{
		cin>>N;
		vector<int> height;
		height.push_back(UNDEFINED);
		int temp;
		for(int i = 0 ;i<N; i++)
		{
			cin>>temp;
			height.push_back(temp);
			
		}
		height.push_back(UNDEFINED);
	
		
		
		int max  = 0;
		int heit = 0;
		for(int i = 1; i<height.size()-1; i++)
		{
			vector<bool> visit(height.size(), false);
			int row = 0;
			findMaxRectangle(height, visit, i, height[i]);
			
			for(int j = 1; j<visit.size()-1; j++)
			{
				if(visit[j] == true)
					row ++;
				
			}
			
			if( heit*max <=  height[i]*row)
			{
				heit= height[i];
				max = row;
			}

			
			
			
		}
		
		
		
		cout<<heit*max<<endl;
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	return 0;
}
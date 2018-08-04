#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



//case 1: 가장 큰 직사각형이 왼쪽에 존재  
//case 2: 가장 큰 직사각형이 오른쪽에 존재 
//case 3: 가장 큰 직사각형이 양쪽에 걸쳐 존재
int fence(const vector<int>& height, int leftIdx, int rightIdx)
{
const int mid = (leftIdx+rightIdx)/2;
//basecase : 부분문제가 하나 남을 경우 즉, leftIdx == rightIdx인 경우
if(leftIdx == rightIdx)
	return height[leftIdx]; //높이가 직사각형의 넓이가 된다.
	
	
//case 3
	
int maxArea = -1;
int rightExpan = mid+1;
int leftExpan = mid;
int curHeight = min(height[rightExpan], height[leftExpan]);
maxArea = max(maxArea, curHeight*2);
	

	while((rightExpan <rightIdx || leftExpan >leftIdx))  //한쪽이 먼저 끝나는 경우도 있기 때문에 모든경우를 돌기 위해서 ||로
	{
	
		int temp;
		//더 높은 값쪽으로 들어가게
		//여기서 한계검사까지 곁붙여준다
		if(rightExpan<rightIdx &&(leftExpan == leftIdx || height[leftExpan-1] < height[rightExpan+1])) //오른쪽확장
		{
			rightExpan++;
			curHeight = min(curHeight, height[rightExpan]);
			
		
		}
		else   //왼쪽확장
		{
			leftExpan--;
			curHeight = min(curHeight, height[leftExpan]);
			
		
			
		}
		maxArea = max(maxArea, curHeight*(rightExpan -leftExpan +1));
		
	}

	
//case 1, 2

	
	
	int maxV = max(fence(height, leftIdx, mid ), fence(height, mid+1, rightIdx));
	
	if(maxV >= maxArea)
		maxArea = maxV;
	

	
	
	return maxArea;	
	
}

int main()
{
	vector<int> height;
	int C, N;
	int temp;
	cin>>C;
	while(C--)
	{
		cin>>N;
		for(int i = 0 ; i<N; i++)
		{
			cin>>temp;
			height.push_back(temp);
			
		}
			
		int value =fence(height,0, height.size()-1);
		
		cout<<value<<endl;
		
		
		
		
		
		
		
		
		
		vector<int>().swap(height);
	}
	
	
	
	
	
	
	
	
	
}







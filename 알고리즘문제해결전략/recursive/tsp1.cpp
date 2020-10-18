//Traveling Salesman Problem 1
//나라 수 : 3~8  index : 1부터
//기본적인 recursive만 이용.
#include <iostream>
#include <vector>
using namespace std;


double arr[9][9] = {0,};
vector<bool> visit(9, false);
vector<double> dist;

bool isVisit(vector<bool>& visit, int idx)
{
	if(visit[idx] == true)
		return true;
	
	
	return false;
}

double TravelAllCities(double arr[9][9], vector<bool>& visit,  int cityIdx,  int allCityNum, double distance = 0, int cityNum = 1 ) //cityIdx == 여행 중인 나라 번호 ,cityNum ==  여행다닌 도시 수, allCityNum == 도시 전체 수
{
	double shortestDist = 100000;
	double curDist;
	if(cityNum == allCityNum  )  //마지막 도시에 도착할 시 (basecase)
	{
		dist.push_back(distance);
		return distance;
	}
	
	
		for(int j = 1; j<=allCityNum; j++)
		{
			if(arr[cityIdx][j] !=0 && !isVisit(visit,j))  //가는 길이 있고, 방문하지 않은 경우
			{
				visit[j] = true;
				curDist = TravelAllCities(arr,visit, j, allCityNum, distance+arr[cityIdx][j], cityNum+1) ;
				if(shortestDist > curDist)
					shortestDist = curDist;
				visit[j] = false;
			}
						
		}

	
	
	return shortestDist;
	
}


int main()
{
	int C, N;
	cout.precision(15);
	cin>>C;
	
	while(C>0)
	{
		double shortDist = 100000;
		double value = 0;
		cin>>N;
		for(int i  = 1; i<=N; i++)
			for(int j = 1; j<=N; j++)
				cin>>arr[i][j];
		
		
				
		for(int i =1; i<=N ; i++)
		{
			visit[i] = true;		
			value = TravelAllCities(arr, visit, i,  N );
			if(shortDist > value)
				shortDist = value;
			visit[i] = false;
		}
		
		
		
	
		cout<<shortDist<<endl;
		
		shortDist =100000;
		C--;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}




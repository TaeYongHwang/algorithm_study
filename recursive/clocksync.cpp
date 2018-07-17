#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> clockAim; //시계가 몇시를 나타내는지표현 (16개)
vector<vector<int> > switchConnected (10, vector<int>(0)); //각 스위치(0~9)와 시계 링크위해
vector<int> answerCase;

bool PushSwitch(vector<int>& caseVector, vector<int>& clockAim, vector<vector<int> >& switchConnected);
void AllCase(int idx) ;

//모든 시계가 12시를 향하는지 알아내는 함수



//[0~3]의 스위치를 누르는 모든 경우의 수 구하는 함수
int caseArr[4] = {0,1,2,3};
vector<int> caseVector;
void AllCase(int idx)  
{
	if(idx>=10)
	{
		vector<int> destVector;
		destVector.assign( clockAim.begin(), clockAim.end() );  //복사
		
		if(PushSwitch(caseVector, destVector, switchConnected) ==true)//이 경우를 갖고 함수를 호출
		{
			int sum=0;
			for(int i = 0; i<caseVector.size(); i++)
				sum+=caseVector[i];
			answerCase.push_back(sum);
			
		}
		
		return;
		
	}
	
	for(int i = 0; i<4; i++)
	{
		caseVector.push_back(i);
		AllCase(idx+1);
		caseVector.pop_back();
	}
	

	
}

//위의 경우로 스위치를 누른 후 모든 시계가 12시를 향하는지
bool PushSwitch(vector<int>& caseVector, vector<int>& clockAim, vector<vector<int> >& switchConnected)
{
	for(int i = 0; i<switchConnected.size() ; i++)  //스위치 갯수반큼 반복
	{
		if(caseVector[i] !=0) //해당 스위치를 한번이라도 누를 경우
		{
			for(int j=0; j<switchConnected[i].size(); j++)
				clockAim[ (switchConnected[i][j]) ] += 3*caseVector[i];  //누른 횟수만큼 시간을 돌림
			
		}
	}
	for(int i = 0 ; i<clockAim.size(); i++)
	{
		if(clockAim[i]%12 ==0 )
			clockAim[i] =12;
		else if(clockAim[i]%12 ==3)
			clockAim[i] = 3;
		else if(clockAim[i]%12 ==6)
			clockAim[i] = 6;
		else if(clockAim[i]%12 ==9)
			clockAim[i] = 9;
	}

	for(vector<int>::size_type i = 0; i<clockAim.size(); i++)
	{
		if(clockAim[i] !=12)
			return false;
		
	}
	
	return true;
}




int main()
{
	
	int C;
	cin>>C;
	
	switchConnected[0].push_back(0);
	switchConnected[0].push_back(1);
	switchConnected[0].push_back(2);
	
	switchConnected[1].push_back(3);
	switchConnected[1].push_back(7);
	switchConnected[1].push_back(9);
	switchConnected[1].push_back(11);
	
	switchConnected[2].push_back(4);
	switchConnected[2].push_back(10);
	switchConnected[2].push_back(14);
	switchConnected[2].push_back(15);
	
	switchConnected[3].push_back(0);
	switchConnected[3].push_back(4);
	switchConnected[3].push_back(5);
	switchConnected[3].push_back(6);
	switchConnected[3].push_back(7);

	switchConnected[4].push_back(6);
	switchConnected[4].push_back(7);
	switchConnected[4].push_back(8);
	switchConnected[4].push_back(10);
	switchConnected[4].push_back(12);
	
	switchConnected[5].push_back(0);
	switchConnected[5].push_back(2);
	switchConnected[5].push_back(14);
	switchConnected[5].push_back(15);
	
	switchConnected[6].push_back(3);
	switchConnected[6].push_back(14);
	switchConnected[6].push_back(15);
	
	switchConnected[7].push_back(4);
	switchConnected[7].push_back(5);
	switchConnected[7].push_back(7);
	switchConnected[7].push_back(14);
	switchConnected[7].push_back(15);
	
	switchConnected[8].push_back(1);
	switchConnected[8].push_back(2);
	switchConnected[8].push_back(3);
	switchConnected[8].push_back(4);
	switchConnected[8].push_back(5);
	
	switchConnected[9].push_back(3);
	switchConnected[9].push_back(4);
	switchConnected[9].push_back(5);
	switchConnected[9].push_back(9);
	switchConnected[9].push_back(13);

	
	
	
	while(C>0)
	{

		int temp;
		for(int i =0; i<16; i++){
			cin>>temp;
			clockAim.push_back(temp);
		}
		

		AllCase(0);
		
		if(answerCase.size()!=0){
			sort(answerCase.begin(), answerCase.end());	
			cout<<answerCase[0]<<endl;
		}
		else
			cout<<-1<<endl;
		
		
		
		answerCase.clear();
		clockAim.clear();
		C--;
	}
	
	
	
	
	
	
	return 0;
}



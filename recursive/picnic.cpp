#include <iostream>
#include <string>
#include <vector>
using namespace std;







int count =0;


//친구관계 판별.
bool isFriend(int num1, int num2, int friendMat[10][10])
{
	if(friendMat[num1][num2] == 1)
		return true;
	
	return false;
	
	
}

//n명을 2명씩 짝짓는 함수
void pick_two(vector<int>& v, int peopleNum, int friendMat[10][10])
{

	

	if(peopleNum ==2)    //기저상태 (값이 두개남은경우)
	{
		if(isFriend(v[0],v[1], friendMat))
			count++;
		return ;
	}
	/*
		for(vector<int>::size_type i = 0;  i<v.size(); i++)
		cout<<v[i]<<' ';
		cout<<endl;
	*/
	int num1, num2;
	//정해진 사람 수에서 두명을 뽑는 방법.
	for(vector<int>::size_type i = 0;  i<peopleNum-1; i++)  
	{
		num1 = v.at(i);
		v.erase(v.begin()+i);
			
		for(vector<int>::size_type j=i ; j<peopleNum-1; j++)   //값한개가 지워진 상태.
		{
			num2 = v.at(j);
			v.erase(v.begin()+j);
			if(isFriend(num1,num2,friendMat))
				pick_two(v,peopleNum-2, friendMat);
			v.insert(v.begin()+j, num2);
			
		}
		v.insert(v.begin()+i, num1);
	}
	

}





int main()
{
	vector<int> v;
	
		
	
	int testCase; //<=50
	int n,m ; //학생 수, 친구쌍의 수
 	cin>>testCase;
	
	//testCase만큼 반복
	for(int i=0; i<testCase; i++)
	{
		int overlabRemove = 0 ;  //블록의 무순서를 위해
		count = 0;
		int friendMat[10][10] ={0, };
		cin>>n>>m;
		
		//학생수만큼 값저장
		for(int j = 0 ; j<n; j++)
			v.push_back(j);
		
		//친구관계 1 : 친구 
		for(int k=0; k<m; k++)
		{
			int value1, value2;
			cin>>value1>>value2;
			friendMat[value1][value2] = 1;
			friendMat[value2][value1] =1;
			
		}
		
		if(v.size()%2 ==0) {
			
			pick_two(v, v.size(), friendMat);
			overlabRemove = v.size()/2;
			for(int re = overlabRemove-1 ; re>0; re--)
				overlabRemove*=re;
			cout<< (count/overlabRemove) <<endl;
	
		}
		else
			cout<<count<<endl;
		
		
		v.clear();
		

	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
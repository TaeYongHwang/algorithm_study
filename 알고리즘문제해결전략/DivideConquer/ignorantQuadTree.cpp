//원래 그림으로 복원했다가 다시 압축하는 방법으로 (무식하게)
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define WHITE 'w'
#define BLACK 'b'
#define UNDEFINED NULL


//깊이 알아내는 함수
int numberOfX(string& str, int cnt =1) //젤 처음 str[0]이 x인 경우에 실행
{
	str.substr(1);
	//basecase : 다음 4문자에 x가 없는 경우
	bool judge = false;
	for(int i = 0 ; i<4; i++)
	{
		if(str[i] =='x'){
			judge = true;
			break;
		}
		
		
	}
	if(judge == false)
	{
		return cnt;
		
	}
	
	//다음 4문자에 x가있는경우 
	
	int value = cnt;
	
		for(int i = 0 ; i<4; i++)   
		{
			int temp ;
			str = str.substr(1);
			if(str[0] == 'x') //x인경우
			{
				temp =  numberOfX(str, cnt+1);
				value = temp;
			}
		}


	return value;
}

//압축된 값을 다시 원래 모양으로 복원시키는 함수
void quadTree(string& str, vector<vector<char> >& v, int size, int rowIdx=0, int columnIdx=0) //처음엔 [0,0]이므로 초기화 size: 한쪽만표시
{
	if(str.empty()) //basecase
		return;
	
	if(str[0] == WHITE || str[0] == BLACK) // 각 사분면이 전부 w, b 인경우  값채우고종료
	{
		for(int i = rowIdx; i<rowIdx+size; i++)
				for(int j = columnIdx; j<columnIdx+size; j++)
					v[i][j] = str[0];
		
		return; 
	}
	if(str[0] == 'x')  //x 들어올 시 다음 값을 재귀적으로 조사
	{

		for(int i = 0 ; i<4; i++)  //각 사분면 조사 (1,2,3,4분면)
		{
			//사분면의 시작 인덱스값과 사이즈 정리
			int newSize = size/2;
			int rowidx[4] = {rowIdx, rowIdx, rowIdx+size/2, rowIdx+size/2};
			int columnidx[4] = {columnIdx, columnIdx+size/2, columnIdx, columnIdx+size/2};
					
			str = str.substr(1);
			quadTree(str, v, newSize, rowidx[i], columnidx[i]);
						
		}
	
	}
}

//상하 반전시키는 함수
vector<vector<char> > upsideDown(vector<vector<char> >& v)
{
	vector<vector<char> > temVec(v);
	
	for(int i = v.size()-1; i>=0 ; i-- )
	{
		for(int j = v[0].size()-1; j>=0 ; j--)
		{
			temVec[i][j] = v[v.size()-1-i][j];
			
			
		}
	}
	
	return temVec;
	
}


bool judgeFunc(vector<vector<char> >& v, char c, int size, int rowIdx, int columnIdx)
{
	for(int i = rowIdx; i<rowIdx+size; i++)
	{
		for(int j = columnIdx ; j<columnIdx+size; j++)
		{
			if(v[i][j] != c)
				return false;
			
		}
		
	}
	
	return true;
	
	
}




//벡터(데이터)를 가지고 압축시키는 함수
string compreStr;
void compression(vector<vector<char> >& v, int size, int rowIdx = 0 , int columnIdx = 0)
{
	//전부 w
	if(judgeFunc(v,'w',size,rowIdx,columnIdx) == true)
	{
		compreStr.push_back('w');
		return;	
	}
	//전부 b
	if(judgeFunc(v,'b',size,rowIdx,columnIdx) == true)
	{
		compreStr.push_back('b');
		return;
	}
	
	//하나라도 다른 경우
	compreStr.push_back('x');
	
	
	for(int i = 0 ; i<4; i++)  //각 사분면 조사 (1,2,3,4분면)
	{
		//사분면의 시작 인덱스값과 사이즈 정리
		int newSize = size/2;
		int rowidx[4] = {rowIdx, rowIdx, rowIdx+size/2, rowIdx+size/2};
		int columnidx[4] = {columnIdx, columnIdx+size/2, columnIdx, columnIdx+size/2};
		compression(v, newSize, rowidx[i], columnidx[i]);
					
	}
	
	
}


int main()
{

	
	
	int C;
	cin>>C;
	
	while(C--)
	{
		string str;
		cin>>str;
		string strtmp = str;
			int cnt = 0;
		if(str[0]=='x')
		{
			cnt = numberOfX(strtmp);
		}
		vector<vector<char> > v(pow(2,cnt), vector<char>(pow(2,cnt), UNDEFINED));
		
		
		quadTree(str, v, v.size());
		
		
		vector<vector<char> > temVec = upsideDown(v);

		compression(temVec, temVec.size());
		
		cout<<compreStr<<endl;
		
		compreStr = "";
		vector<vector<char> >().swap(temVec);
		vector<vector<char> >().swap(v);
		
	}
	
	
	
	
	return 0;
}
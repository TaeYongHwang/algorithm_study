#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<string> rightAnswer;
string wildStr;

int cache[100];
int cacheIdx;

int wildcard(string &str, int idx = 0 , int wildIdx = 0)
{
	
	//**인경우(압축먼저) :
	if(wildStr[wildIdx] == '*' && wildStr[wildIdx+1] == '*' )
	{
		wildcard(str,idx, wildIdx+1);
	}
	
	
	//basecase : str의 끝(null)에 도달한 경우.
		//1.wildStr도 끝에 도달한 경우
		//2.wildStr이 더 남은경우  
	if(str.size() == idx)
	{
		if(wildStr.size() == wildIdx)
		{
			if(cache[cacheIdx] ==-1)
			{
				cache[cacheIdx] =1;
				rightAnswer.push_back(str);
			}
			return 1;
			
		}
		else
		{
			if(wildStr.size()-1 == wildIdx && wildStr[wildIdx] == '*')
			{
				if(cache[cacheIdx] ==-1)
				{
					cache[cacheIdx] =1;
					rightAnswer.push_back(str);
				}
				return 1;
			}
			else
				return 0;
			
		}
				
	}

	
	
	
	
	
	//기본 연산 (wildStr의 해당 인덱스 값을 '?' , '*', the others로 나눠서 
	
	if(wildStr[wildIdx] == '?' || wildStr[wildIdx] == str[idx] )
	{
		wildcard(str, idx+1, wildIdx+1);
		
	}
	

	
	//*인 경우 :  
	else if(wildStr[wildIdx] == '*')
	{
		int temIdx = -1;
		for(int i = idx; i<str.size(); i++)
		{
			if(wildStr[wildIdx+1] == str[i] || wildStr[wildIdx+1] == '?')
			{
				temIdx = i;
				wildcard(str, i+1, wildIdx+2);
				
			}
			
			
		}
		
		if(temIdx == -1)
		{
			wildcard(str, idx+1, wildIdx);
		}
		
		
	
		
	}	
	
}

int main()
{
	int C, fileNum;
	

	cin>>C;
	while(C--)
	{
		cin>>wildStr>>fileNum;
		
		vector<string> strV;
		string tem;
		while(fileNum--)
		{
			cin>>tem;
			strV.push_back(tem);
						
		}
		
		
		for(int i = 0 ; i<strV.size(); i++)
		{
			cache[i] = -1;
			cacheIdx = i;
			wildcard(strV[i]);
		}
		
		
		sort(rightAnswer.begin(), rightAnswer.end());
	
		for(int i = 0 ; i<rightAnswer.size() ; i++)
			cout<<rightAnswer[i]<<endl;
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		vector<string>().swap(strV);
		rightAnswer.clear();
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}







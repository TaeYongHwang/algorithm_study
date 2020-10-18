#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<bool> v;


int xcase[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int ycase[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char arr[5][5] ={
	{'U','R','L','P','M'},
	{'X','P','R','E','T'},
	{'G','I','A','E','T'},
	{'X','T','N','Z','Y'},
	{'X','P','Q','R','S'}
};


//시작점 (x,y)에서 단어가 있는지 찾는 시스템.
void hasWord(int y,int x, char* word, int wordLen=0 )
{
	if(arr[x][y] == word[wordLen] && strlen(word) == wordLen+1)
	{
		v.push_back(true);		
	}
	
	if(arr[x][y] == word[wordLen])
	{
		for(int i = 0; i<8; i++)
		{
			int temY = y+ycase[i];
			int temX = x+xcase[i];
			
			if(temY>=0 && temY<5 && temX>=0 && temX<5)
			{
				 hasWord(temY, temX, word, wordLen+1);
			}		
			
		}
		
	}
	
}


int main()
{
	/*
	for(int i= 0 ; i<5; i++){
		for(int j=0; j<5; j++)
			cout<<arr[i][j]<<' ';
	cout<<endl;
	}*/
	
	char* word ="URLPMT";
	
	
	bool tf = false;
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			hasWord(j,i,word);
			if(!v.empty())
				break;
			
		}
		if(!v.empty())
			break;

		
	}
	
	if(!v.empty())
		cout<<"값 있다.";
	else
		cout<<"값 없다.";
	
	
	
	return 0;
}








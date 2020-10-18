#include <iostream>
#include <vector>

#define DIV 100000007
using namespace std;



//매트릭스
vector<vector<int>> makeMat(int k) {
	//k인 겅우 K+2 X K+2 행렬이 생성됨
	vector<vector<int>> mat = vector<vector<int>>(k+2, vector<int>(k+2, 0));

	mat[0][0] ++;
	mat[0][mat.size() - 2] ++;

	for (int i = 1, j = 0; i < mat.size(); i++, j++) {
		mat[i][j] ++;
	}

	/*
	for (int i = 0; i < k+2; i++) {
		for (int j = 0; j < k+2; j ++ ) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	} 
	*/
	
	return mat;

}

//초기값 구하기 [0,ㅏ+1]까지는 알아야되므로
//여기까지는 점화식을 이용해서 구한다.
vector<int> makeInit(int k){
	vector<int> mat = vector <int>( k + 2, -1);

	mat[0] = 1;
	for (int i = 1; i < mat.size(); i++) {

		if (i - k - 1 >= 0)
			mat[i] = mat[i - 1] + mat[i - k - 1];
		else
			mat[i] = mat[i - 1];
	}

	/*
	for (int i = 0; i < mat.size(); i++) {
		cout << mat[i] << ' ';
	}
	cout << endl;
	*/
	return mat;
}
vector<vector<int>> matCal(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
	int size = mat1.size();
	vector<vector<int>> ret = vector<vector<int>>(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			long long temp= 0;
			for (int k = 0; k <size; k++) {
				temp += ((long long)mat1[i][k] * (long long)mat2[k][j]) % DIV;
				temp %= DIV;
			}
			ret[i][j] = (int)temp;
		}
	}

	return ret;
}
vector<vector<int>> resultMat(vector<vector<int>>& original, int count) {

	if (count == 1)
		return original;


	if (count % 2 == 1) {
		return matCal(original, resultMat(original, count-1));
	}
	else {
		vector<vector<int>> temp;
		temp = resultMat(original, count / 2);
		return matCal(temp, temp);
	}
}






int findAns(int N, int K) {
	vector<vector<int>> calMat = makeMat(K);
	vector<int> initMat = makeInit(K);
	
	//n만큼 하기위해 행렬을 N-K만큼 곱해주면 됨
	if (N < initMat.size()) {
		return initMat[N ];
	}

	calMat = resultMat(calMat, N - K);
	/*
	for (int i = 0; i < calMat.size(); i++) {
		cout << calMat[0][i] << ' ';
	}
	cout << endl;
	*/
	long long ans = 0;
	for (int i = 0; i < initMat.size(); i++) {
		ans += ((long long)initMat[i] * (long long)calMat[0][i])%DIV;
		ans = ans % DIV;
	}


	return ans;

}



int main() {
	int T;
	cin >> T;

	while (T--) {
		int K, N;
		cin >> K >> N;

		cout<< findAns(N, K)<<endl;
	}





	return 0;
}
#include <iostream>
#include "treap.h"
using namespace std;


#define MOD 20090711




int N, a, b, prev_num = 1983;

int make_input()
{
	long long temp = ((long long)prev_num * a +b)%MOD;

	//cout << temp << endl;


	return prev_num = temp;
}


int find_mean_sum()
{
	int sum = 1983;
	Node * root = new Node(prev_num);

	//N-1¹ø ¹Ýº¹½ÃÅ²´Ù.
	for (int i = 0; i < N -1; i++) {
		root = root->insert(root, new Node(make_input()));
		int size = root->size;

				if (size % 2 == 1) {
			sum += (root->kth(root, size / 2+1))->key;

			//cout << "È¦¼ö  : " << (root->kth(root, size / 2))->key << endl;


		}
		else {
			int mean1 = root->kth(root, size / 2 +1)->key;
			int mean2 = root->kth(root, size / 2)->key;
		
			//cout << "Â¦¼ö : " << (mean1 > mean2 ? mean2 : mean1) << endl;

			sum += (mean1 > mean2 ? mean2 : mean1);
		}

		//cout << "sum : " << sum << endl;


		sum %= MOD;
	}
	

	return sum;
}










int main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> N >> a >> b;
		prev_num = 1983;

		cout << find_mean_sum() << endl;





	}





	return 0;
}
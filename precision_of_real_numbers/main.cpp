// ACM Mid-Atlantic United States 2001
// run test to see the sample 

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;

	cin >> N;
	double x, y;
	for(int i = 0; i < N; i++) {
		cin >> x >> y;
		double cur = (x * x + y * y) * 3.14159265 / 100;
		cur = ceil(cur);
		cout << "Property " << i << ": This property will begin eroding in year " << cur << endl;
	}
	cout << "END" << endl;

}

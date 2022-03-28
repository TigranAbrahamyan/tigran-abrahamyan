#include <iostream>
using namespace std;

int main() {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	cout << "Input A(x1, y1): " << endl;
	cin >> x1 >> y1;

	cout << "Input B(x2, y2): " << endl;
	cin >> x2 >> y2;

	cout << "Input C(x3, y3): " << endl;
	cin >> x3 >> y3;

	cout << "Input D(x4, y4): " << endl;
	cin >> x4 >> y4;

	if ((x1 == x2 && y3 == y4) || (x3 == x4 && y1 == y2)) {
		cout << "Yes" << endl;
	}

	return 0;
}

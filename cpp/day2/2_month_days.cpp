#include <iostream>

using namespace std;

int main() {
	int monthNumber = 0;

	cout << "Input a month number: ";
	cin >> monthNumber;

	switch (monthNumber) {
		case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
			cout << "Total number of days = 31" << endl;
			break;
		case 4:
    case 6:
    case 9:
    case 11:
			cout << "Total number of days = 30" << endl;
			break;
    case 2:
			cout << "Total number of days = 28" << endl;
			break;
		default:
			cout << "Month not found" << endl;
			break;
	}

	return 0;
}

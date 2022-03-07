#include <iostream>

using namespace std;

string printMonthTotalDays() {
	int monthNumber = 0;
	string result = "Total number of days = ";

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
			result = result + "31";
			break;
		case 4:
    case 6:
    case 9:
    case 11:
			result = result + "30";
			break;
    case 2:
			result = result + "28";
			break;
		default:
			result = "Month not found";
			break;
	}

	return result;
}

int main() {
	string monthTotalDays = printMonthTotalDays();
	cout << monthTotalDays;

	return 0;
}

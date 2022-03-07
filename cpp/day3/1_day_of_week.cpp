#include <iostream>

using namespace std;

string findWeek() {
	int week = 0;
	string result = "";

	cout << "Input a week number: ";
	cin >> week;

	switch (week) {
		case 1:
			result = "Monday";
			break;
		case 2:
			result = "Tuesday";
			break;
		case 3:
			result = "Wednesday";
			break;
		case 4:
			result = "Thursday";
			break;
		case 5:
			result = "Friday";
			break;
		case 6:
			result = "Saturday";
			break;
		case 7:
			result = "Sunday";
			break;
		default:
			result = "Week not found";
			break;
	}

	return result;
}

int main() {
	string week = findWeek();
	cout << week << endl;

	return 0;
}

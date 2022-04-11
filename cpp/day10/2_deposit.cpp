#include <iostream>
#include <cmath>

using namespace std;

string MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void getMonthDayAndYear(string, string*, int*, int*, int*);

int main(int argc, char* argv[]) {
	float sum = atof(argv[1]);
	float percent = atof(argv[2]) / 12.0;
	int month = atoi(argv[3]);

	time_t t = time(0);
  string dateTime = ctime(&t);
	string currentMonth;
	int currentMonthNumber;
	int currentDay;
	int currentYear;

	getMonthDayAndYear(dateTime, &currentMonth, &currentMonthNumber, &currentDay, &currentYear);

	int monthPosition = currentMonthNumber;

  cout.precision(2);
  cout << fixed;

	cout << "|===============================================|" << endl;
	cout << "| " << dateTime;
	cout << "|===============================================|" << endl;
	cout << "| Month\t | Total sum\t | Income\t | Year |" << endl;
	cout << "|===============================================|" << endl;

	for (int i = currentMonthNumber; i <= currentMonthNumber + month; i++) {
		float income = (sum * percent) / 100.0;
		sum += income;

		if (i % 12 == 1) {
			currentYear++;
			monthPosition = 1;
			cout << endl << "|===============================================|" << endl;
		}

		cout << "| " << MONTHS[monthPosition - 1] << "\t | " << sum << "\t | " << income;

		if (monthPosition == 1) {
			cout << "\t | " << currentYear << " |" << endl;
		} else {
			cout << "\t | \t" << "|"  << endl;
		}

		monthPosition++;
	}

	cout << "|===============================================|" << endl;

	return 0;
}

void getMonthDayAndYear(string currentTime, string *month, int *monthNumber, int *day, int *year) {
	string date[5] = {};
	int dateIndex = 0;

	for (int i = 0; currentTime[i] != '\0'; i++) {
		if (currentTime[i] == ' ') {
			dateIndex++;
			continue;
		}

		date[dateIndex] += currentTime[i];
	}

	for (int i = 0; i < 12; i++) {
		if (date[1] == MONTHS[i]) {
			*month = MONTHS[i];
			*monthNumber = i + 1;
			break;
		}
	}

	*day = stoi(date[2]);
	*year = stoi(date[4]);
}

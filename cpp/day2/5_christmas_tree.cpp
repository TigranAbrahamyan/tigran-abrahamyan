#include <iostream>
using namespace std;

void firstTree(int size) {
	int row = 1;

	while (row <= size) {
		int column = 1;

		while (column <= row) {
			cout << "* ";
			column++;
		}

		cout << endl;
		row++;
	}	
}

void secondTree(int size) {
	int row = size;	

	while (row >= 1) {
		int column = row;

		while (column >= 1) {
			cout << "* ";
			column--;
		}

		cout << endl;
		row--;
	}
}

void thirdTree(int size) {
	int row = size;

	while (row >= 1) {
		int column = size;

		while (column >= 1) {
			if (column <= row) {
				cout << "* ";
			} else {
				cout << "  ";
			}
	
			column--;
		}

		cout << endl;
		row--;
	}
}

void fourthTree(int size) {
	int row = 1;

	while (row <= size) {
		int column = size;

		while (column >= 1) {
			if (column <= row) {
				cout << "* ";
			} else {
				cout << "  ";
			}
	
			column--;
		}

		cout << endl;
		row++;
	}
}

void pyramid(int size) {
	int row = 1;

	while (row <= size) {
		int column = size;

		while (column >= 1) {
			if (column <= row) {
				cout << "* ";
			} else {
				cout << " ";
			}
	
			column--;
		}

		cout << endl;
		row++;
	}
}

void reversedPyramid(int size) {
	int row = size;

	while (row >= 1) {
		int column = size;

		while (column >= 1) {
			if (column <= row) {
				cout << "* ";
			} else {
				cout << " ";
			}
	
			column--;
		}

		cout << endl;
		row--;
	}
}


int main() {
	int size;

	cout << "Write a size: ";
	cin >> size;

	firstTree(size);
	cout << endl;

	secondTree(size);
	cout << endl;

	thirdTree(size);
	cout << endl;

	fourthTree(size);
	cout << endl;

	pyramid(size);
	cout << endl;

	reversedPyramid(size);

	return 0;
}


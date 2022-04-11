#include <iostream>
#include <fstream>

using namespace std;

const int PARAMETERS_COUNT = 4;
const int maxRoomsCount = 10;

struct Check {
	string name;
	string city;
};

struct Room {
	int number;
	int price;
};

struct Hotel {
	string name;
	string city;
	int stars;
	string swimmingPool;
	Room room[maxRoomsCount];
} hotel;

int getHotelsLength() {
  int result = 0;
  string fileLine = "";
  ifstream hotelsFile("hotels.txt");

  while (getline(hotelsFile, fileLine)) {
    result++;
  }

  hotelsFile.close();

  return result;
}

int main() {
	const int size = 5;
	const int hotelsLength = getHotelsLength();
	string str;
	string array[size];
	Check check[hotelsLength];
	ifstream file("hotels.txt");
	int k = 0;
	while (getline(file, str)) {
		int j = 0;
		array[0] = "";
		array[1] = "";
		for (int i = 0; str[i] != '['; i++) {
			if (str[i] == ',') {
				j++;
				if (str[i + 1] == ' ') {
					i++;
				}
				continue;
			}
			array[j] += str[i];
		}
		check[k].name = array[0];
		check[k].city = array[1];
		k++;
	}
	int fileSize = k - 1;
	file.close();
	ofstream agent("hotels.txt", ios::app);
	cout << "Input hotel name: ";
	getline(cin, hotel.name);
	cout << "Input city: ";
	getline(cin, hotel.city);
	for (int i = 0; i <= fileSize; i++) {
		if (check[i].name == hotel.name && check[i].city == hotel.city) {
			cout << "This hotel is already registered!\n";
			return 0;
		}
	}
	do {
		cout << "Input stars(1-5): ";
		cin >> hotel.stars;
	} while (hotel.stars < 1 || hotel.stars > 5);

	do {
		cout << "Swimming Pool (input yes / no): ";
		cin >> hotel.swimmingPool;
	} while (hotel.swimmingPool != "yes" && hotel.swimmingPool != "no");

	int roomIndex;
	int roomTypesNumber;

	do {
		cout << "How many type number of rooms are there?(1-10): ";
		cin >> roomTypesNumber;
	} while (roomTypesNumber < 1 || roomTypesNumber > 10);

	for (int i = 0; i < roomTypesNumber; i++) {
		string placesOfRoom;
		cout << "number of places of rooms->price: ";
		cin >> placesOfRoom;

		string arr[2] = {};
		int j = 0;

		for (int i = 0; i < placesOfRoom.length(); i++) {
			if (placesOfRoom[i] == '-') {
				j++;
				if (placesOfRoom[i + 1] == '>') {
					i++;
				}
				continue;
			}
			arr[j] += placesOfRoom[i];
		}

		hotel.room[roomIndex].number = stoi(arr[0]);
		hotel.room[roomIndex].price = stoi(arr[1]);
		roomIndex++;
	}

	agent << hotel.name + ", " + hotel.city + ", " + to_string(hotel.stars) + ", " + hotel.swimmingPool + ", [" ;

	for (int i = 0; i < maxRoomsCount; i++) {
		if (!hotel.room[i].number ||  !hotel.room[i].price) {
			continue;
		}

		agent << hotel.room[i].number << "-" << hotel.room[i].price;

		if (i != roomIndex - 1) {
			agent << ", ";
		}
	}

	agent << "]" << endl;
	agent.close();
	cout << "Your hotel is registered!" << endl;

	return 0;
}

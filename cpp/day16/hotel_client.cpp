#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

#include "../lib/alphabet/alphabet.h"

using namespace std;

ifstream HOTELS_FILE;
const string HOTELS_FILENAME = "hotels.txt";
ifstream BOOKED_HOTELS_FILE;
const string BOOKED_HOTELS_FILENAME = "booked.txt";
int MONTH_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

enum HotelMenuEnum {
  SHOW_ALL = 0,
  FILTER_BY_CITY = 1,
  FILTER_BY_STARS = 2,
  BOOK_HOTEL = 3
};

struct Room {
  string numberOfPlaces;
  string price;
};

struct Hotel {
	int id;
  string name;
  string city;
  string stars;
  string swimmingPool;
  vector<Room> rooms;
};

struct BookedHotel {
  string name;
  string city;
  string numberOfPlaces;
  string startDate;
  string endDate;
};

string getConvertedDate(int, int, int);
void printErrorMessage(string);
void getSplittedDate(string, string*, int*, int*, int*);
void initHotels(vector<Hotel>&);
void initBookedHotels(vector<BookedHotel>&);
void eraseHotelsEndDatePast(int, int, int);
void showMenu();
void showHotels(vector<Hotel>&);
void filterByOption(vector<Hotel>&, int, string);
void bookHotel(vector<Hotel>&, vector<BookedHotel>&, int, int, int);
void hotelFiltration(vector<Hotel>&, vector<BookedHotel>&, int, int, int);

int main() {
  time_t date = time(NULL);
  struct tm *localDate = localtime(&date);
  int currentDay = localDate->tm_mday;
  int currentMonth = localDate->tm_mon + 1;
  int currentYear = localDate->tm_year + 1900;

  vector<Hotel> hotels;
  vector<BookedHotel> bookedHotels;
  initHotels(hotels);
  initBookedHotels(bookedHotels);
  eraseHotelsEndDatePast(currentDay, currentMonth, currentYear);
  hotelFiltration(hotels, bookedHotels, currentDay, currentMonth, currentYear);

  return 0;
}

string getConvertedDate(int day, int month, int year) {
  const string convertedStartDay = day < 10 ? "0" + to_string(day) : to_string(day);
  const string convertedStartMonth = month < 10 ? "0" + to_string(month) : to_string(month);
  const string convertedStartYear = to_string(year);

  return convertedStartDay + "/" + convertedStartMonth + "/" + convertedStartYear;
}

void printErrorMessage(string error) {
  cout << error << ", input again" << endl;
}

void getSplittedDate(string date, string *dateParts, int *day, int *month, int *year) {
	int datePartsIndex = 0;

	for (int i = 0; date[i] != '\0'; i++) {
		if (date[i] == '/' || date[i] == '.' || date[i] == '-') {
			datePartsIndex++;
			continue;
		}

		dateParts[datePartsIndex] += date[i];
	}

	*day = stoi(dateParts[0]);
	*month = stoi(dateParts[1]);
	*year = stoi(dateParts[2]);
}

void initHotels(vector<Hotel> &hotels) {
  try {
    HOTELS_FILE.open(HOTELS_FILENAME);

    if (HOTELS_FILE.fail()) {
      throw ("File " + HOTELS_FILENAME + " not found");
    }

    string fileLine = "";
		int id = 0;

    while (getline(HOTELS_FILE, fileLine)) {
      Hotel hotel = {};
      Room room = {};
      int hotelInfoIndex = 1;
      int roomInfoIndex = 1;
      bool isHotelInfoQueue = true;

      for (int i = 0; i < fileLine.length(); i++) {
        // check if room parsing should start
        if (fileLine[i] == '[') {
          isHotelInfoQueue = false;
          continue;
        }

        /**
         * if case - parsing hotel info
         * else case - parsing information about hotel rooms
        */
        if (isHotelInfoQueue) {
          // get next hotel field divided by comma
          if (fileLine[i] == ',' && fileLine[i + 1] == ' ') {
            i++;
            hotelInfoIndex++;
						hotel.id = id;
            continue;
          }

          /**
           * split hotel info data
           * 1 - name
           * 2 - city
           * 3 - stars
           * 4 - swimming pool
          */
          switch (hotelInfoIndex) {
            case 1:
              hotel.name += fileLine[i];
              break;
            case 2:
              hotel.city += fileLine[i];
              break;
            case 3:
              hotel.stars += fileLine[i];
              break;
            case 4:
              hotel.swimmingPool += fileLine[i];
              break;
          }
        } else {
          // get next room information divided by comma
          if (fileLine[i] == ',' && fileLine[i + 1] == ' ' || fileLine[i] == ']') {
            i++;
            hotel.rooms.push_back(room);
            // reset room options
            room = {};
            roomInfoIndex = 1;
            continue;
          }

          // get next room field divided by dash
          if (fileLine[i] == '-') {
            roomInfoIndex++;
            continue;
          }

          /**
           * split hotel rooms info data
           * 1 - number
           * 2 - price
          */
          switch (roomInfoIndex) {
            case 1:
              room.numberOfPlaces += fileLine[i];
              break;
            case 2:
              room.price += fileLine[i];
              break;
          }
        }
      }

      hotels.push_back(hotel);
			id++;
    }

    HOTELS_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    HOTELS_FILE.close();
    exit(0);
  }
}

void initBookedHotels(vector<BookedHotel> &bookedHotels) {
  try {
    BOOKED_HOTELS_FILE.open(BOOKED_HOTELS_FILENAME);

    if (BOOKED_HOTELS_FILE.fail()) {
      throw ("File " + BOOKED_HOTELS_FILENAME + " not found");
    }

    string fileLine = "";

    while (getline(BOOKED_HOTELS_FILE, fileLine)) {
      BookedHotel bookedHotel = {};
      int bookedHotelInfoIndex = 1;

      for (int i = 0; i < fileLine.length(); i++) {
        if (fileLine[i] == '-') {
          bookedHotelInfoIndex++;
          continue;
        }

        if (fileLine[i] == ',' && fileLine[i + 1] == ' ') {
          i++;
          bookedHotelInfoIndex++;
          continue;
        }

        switch (bookedHotelInfoIndex) {
          case 1:
            bookedHotel.name += fileLine[i];
            break;
          case 2:
            bookedHotel.city += fileLine[i];
            break;
          case 3:
            bookedHotel.numberOfPlaces += fileLine[i];
            break;
          case 4:
            bookedHotel.startDate += fileLine[i];
            break;
          case 5:
            bookedHotel.endDate += fileLine[i];
            break;
        }
      }

      bookedHotels.push_back(bookedHotel);
    }

    BOOKED_HOTELS_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    BOOKED_HOTELS_FILE.close();
    exit(0);
  }
}

void eraseHotelsEndDatePast(int currentDay, int currentMonth, int currentYear) {
  BOOKED_HOTELS_FILE.open(BOOKED_HOTELS_FILENAME);
  string fileLine = "";
  ofstream temp("temp.txt");
  int fileEndDay, fileEndMonth, fileEndYear;

  while (getline(BOOKED_HOTELS_FILE, fileLine)) {
    string fileLineEndDate = fileLine.substr(fileLine.length() - 10);
    string splittedFileEndDate[3] = {};
    getSplittedDate(fileLineEndDate, splittedFileEndDate, &fileEndDay, &fileEndMonth, &fileEndYear);

    if (currentYear > fileEndYear) {
      continue;
    }

    if (currentYear == fileEndYear && currentMonth > fileEndMonth) {
      continue;
    }

    if (currentYear == fileEndYear && currentMonth == fileEndMonth && currentDay > fileEndDay) {
      continue;
    }

    temp << fileLine << endl;
  }

  temp.close();
  BOOKED_HOTELS_FILE.close();
  remove("booked.txt");
  rename("temp.txt", "booked.txt");
}

void showMenu() {
  cout << "==================================" << endl;
  cout << "0) Show all hotels" << endl;
  cout << "1) Search hotel by city" << endl;
  cout << "2) Search hotel by stars" << endl;
  cout << "3) Book hotel" << endl;
  cout << "9) Exit (or another key)" << endl;
  cout << "==================================" << endl;
}

void showHotels(vector<Hotel> &hotels) {
  cout << "==================================================================================================================" << endl;
  cout << "ID \t | Name \t\t | City \t\t | Stars | Swimming pool | Room number \t\t\t | Room number price daily" << endl;
  cout << "==================================================================================================================" << endl;
  for (int i = 0; i < hotels.size(); i++) {
    cout << hotels[i].id << "\t | ";
    cout << hotels[i].name << (hotels[i].name.length() <= 11 ? "\t\t" : "\t") << " | ";
    cout << hotels[i].city << (hotels[i].city.length() <= 11 ? "\t\t" : "\t") << " | ";
    cout << hotels[i].stars << "     | ";
    cout << hotels[i].swimmingPool << "\t\t | ";

    const int roomsSize = hotels[i].rooms.size();

    for (int j = 0; j < roomsSize; j++) {
      cout << hotels[i].rooms[j].numberOfPlaces;
      if (j != roomsSize - 1) {
        cout << ", ";
      }
    }

    if (roomsSize * 2 <= 4) {
      cout << "\t\t\t\t";
    }

    if (roomsSize * 2 > 4 && roomsSize * 2 < 12) {
      cout << "\t\t\t";
    }

    if (roomsSize * 2 >= 12) {
      cout << "\t";
    }

    cout << " | ";

    for (int j = 0; j < roomsSize; j++) {
      cout << hotels[i].rooms[j].price;
      if (j != roomsSize - 1) {
        cout << ", ";
      }
    }

    cout << endl;
  }

  cout << "==================================================================================================================" << endl << endl;
}

void hotelFiltration(vector<Hotel> &hotels, vector<BookedHotel> &bookedHotels, int currentDay, int currentMonth, int currentYear) {
  while (true) {
    showMenu();
    int option;
    cout << "Option: ";
    cin >> option;

    if (option != SHOW_ALL && option != FILTER_BY_CITY && option != FILTER_BY_STARS && option != BOOK_HOTEL) {
      break;
    }

    switch (option) {
      case SHOW_ALL:
        showHotels(hotels);
        break;
      case FILTER_BY_CITY:
        filterByOption(hotels, option, "city");
        break;
      case FILTER_BY_STARS:
        filterByOption(hotels, option, "stars");
        break;
      case BOOK_HOTEL:
        bookHotel(hotels, bookedHotels, currentDay, currentMonth, currentYear);
        break;
    }
  }
}

void filterByOption(vector<Hotel> &hotels, int mode, string ctx) {
  vector<Hotel> filteredHotels;
  bool isFound = false;

  string option;
  cout << "Input " << ctx << ": ";
  cin >> option;

  for (int i = 0; i < hotels.size(); i++) {
    if (
      (mode == FILTER_BY_CITY && strToLower(hotels[i].city) == strToLower(option))
      || (mode == FILTER_BY_STARS && stoi(hotels[i].stars) == stoi(option))
    ) {
      filteredHotels.push_back(hotels[i]);
      isFound = true;
    }
  }

  if (isFound) {
    showHotels(filteredHotels);
  } else {
    cout << "Hotel not found" << endl;
  }
}

void bookHotel(vector<Hotel> &hotels, vector<BookedHotel> &bookedHotels, int currentDay, int currentMonth, int currentYear) {
  int hotelId;

  while (true) {
    cout << "Input hotel id: ";
    cin >> hotelId;

    if (hotelId > 0 && hotelId < hotels.size()) {
      break;
    } else {
      printErrorMessage("Hotel id not found");
    }
  }

  int countRoomsOfBookedHotel = 0;
  const int hotelRoomsSize = hotels[hotelId].rooms.size();
  cout << "All number places in the room of '" << hotels[hotelId].name << "' hotel in city '" << hotels[hotelId].city << "' - (";

  for (int i = 0; i < hotelRoomsSize; i++) {
    cout << hotels[hotelId].rooms[i].numberOfPlaces;
    if (i != hotelRoomsSize - 1) {
      cout << ", ";
    }
  }

  cout << "), already booked rooms (";

  for (int i = 0; i < bookedHotels.size(); i++) {
    if (bookedHotels[i].name == hotels[hotelId].name && bookedHotels[i].city == hotels[hotelId].city) {
      cout << bookedHotels[i].numberOfPlaces;
      countRoomsOfBookedHotel++;
      if (i != bookedHotels.size() - 1) {
        cout << ", ";
      }
    }
  }

  cout << ")" << endl;
  cout << "==================================" << endl;
  cout << " Places  | Price daily" << endl;
  cout << "==================================" << endl;

  for (int i = 0; i < hotelRoomsSize; i++) {
    cout << "    " << hotels[hotelId].rooms[i].numberOfPlaces << "\t | $";
    cout << hotels[hotelId].rooms[i].price << endl;
  }

  cout << "==================================" << endl;

  if (countRoomsOfBookedHotel == hotelRoomsSize) {
    cout << "This hotel has no available rooms" << endl;
    exit(0);
  }

  string numberOfPlaces;
  int numberOfPlacesIndex;

  while (true) {
    cout << "Input number of places in the room: ";
    cin >> numberOfPlaces;
    bool isExistsNumberOfPlaces = false;
    bool isBooked = false;

    for (int i = 0; i < hotelRoomsSize; i++) {
      if (stoi(hotels[hotelId].rooms[i].numberOfPlaces) == stoi(numberOfPlaces)) {
        numberOfPlacesIndex = i;
        isExistsNumberOfPlaces = true;
      }
    }

    if (isExistsNumberOfPlaces) {
      for (int i = 0; i < bookedHotels.size(); i++) {
        if (bookedHotels[i].name == hotels[hotelId].name && bookedHotels[i].city == hotels[hotelId].city && stoi(bookedHotels[i].numberOfPlaces) == stoi(numberOfPlaces)) {
          isBooked = true;
        }
      }
    } else {
      printErrorMessage("Number of places not exists");
      continue;
    }

    if (!isBooked) {
      break;
    } else {
      printErrorMessage("Number is already booked");
    }
  }

  int startDay, startMonth, startYear;
  int endDay, endMonth, endYear;

  while (true) {
    string startDate;
    cout << "Input start date - format (dd/mm/yyyy): ";
    cin >> startDate;

    string startDateParts[3] = {};
    getSplittedDate(startDate, startDateParts, &startDay, &startMonth, &startYear);

    MONTH_DAYS[1] = startYear % 4 == 0 ? 29 : 28;

    if (startDay > MONTH_DAYS[startMonth - 1] || startMonth > 12 || startYear < 1900) {
      printErrorMessage("Invalid date");
      continue;
    }

    if (startYear > currentYear) {
      break;
    }

    if (startYear == currentYear && startMonth > currentMonth) {
      break;
    }

    if (startYear == currentYear && startMonth == currentMonth && startDay >= currentDay) {
      break;
    }

    printErrorMessage("Start date should be in the future");
  }

  while (true) {
    string endDate;
    cout << "Input end date - format (dd/mm/yyyy): ";
    cin >> endDate;

    string endDateParts[3] = {};
    getSplittedDate(endDate, endDateParts, &endDay, &endMonth, &endYear);

    MONTH_DAYS[1] = endYear % 4 == 0 ? 29 : 28;

    if (endDay > MONTH_DAYS[endMonth - 1] || endMonth > 12 || endYear < 1900) {
      printErrorMessage("Invalid date");
      continue;
    }

    if (endYear > startYear) {
      break;
    }

    if (endYear == startYear && endMonth > startMonth) {
      break;
    }

    if (endYear == startYear && endMonth == startMonth && endDay > startDay) {
      break;
    }

    printErrorMessage("End date should be greater than start date");
  }

  int startTotal = (startYear * 365) + (startMonth * 30) + startDay;
  int endTotal = (endYear * 365) + (endMonth * 30) + endDay;
  int startEndDaysDiff = endTotal - startTotal;

  cout << "Price that you need to pay for '"
    << numberOfPlaces << "' number of places in '" << startEndDaysDiff << "' days on the '"
    << hotels[hotelId].name << "' hotel on city '" << hotels[hotelId].city << "', is: $"
    << startEndDaysDiff * stoi(hotels[hotelId].rooms[numberOfPlacesIndex].price) << endl;

  const string convertedStartDate = getConvertedDate(startDay, startMonth, startYear);
  const string convertedEndDate = getConvertedDate(endDay, endMonth, endYear);

  ofstream outputBookedFile(BOOKED_HOTELS_FILENAME, ios::app);

  outputBookedFile <<
    hotels[hotelId].name + ", " + hotels[hotelId].city + ", " + numberOfPlaces + ", " + convertedStartDate + "-" + convertedEndDate << endl;

  outputBookedFile.close();
  exit(0);
}

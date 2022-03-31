#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream HOTELS_FILE;
const string HOTELS_FILENAME = "hotels.txt";

struct Room {
  string number;
  string count;
  string price;
};

struct Hotel {
  string name;
  string city;
  string stars;
  string swimmingPool;
  vector<Room> rooms;
};

void initializeHotels(vector<Hotel>&);
void showMenu();

int main() {
  vector<Hotel> hotels;
  initializeHotels(hotels);

  for (int i = 0; i < hotels.size(); i++) {
    cout << hotels[i].name << " ";
    cout << hotels[i].city << " ";
    cout << hotels[i].stars << " ";
    cout << hotels[i].swimmingPool << " ";

    for (int j = 0; j < hotels[i].rooms.size(); j++) {
      cout << hotels[i].rooms[j].number << " ";
      cout << hotels[i].rooms[j].count << " ";
      cout << hotels[i].rooms[j].price << " ";
    }

    cout << endl;
  }

  return 0;
}

void initializeHotels(vector<Hotel> &hotels) {
  try {
    HOTELS_FILE.open(HOTELS_FILENAME);

    if (HOTELS_FILE.fail()) {
      throw ("File " + HOTELS_FILENAME + " not found");
    }

    string fileLine = "";

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
           * 2 - count
           * 3 - price
          */
          switch (roomInfoIndex) {
            case 1:
              room.number += fileLine[i];
              break;
            case 2:
              room.count += fileLine[i];
              break;
            case 3:
              room.price += fileLine[i];
              break;
          }
        }
      }

      hotels.push_back(hotel);
    }

    HOTELS_FILE.close();
  } catch (const string err) {
    cout << err << endl;
    HOTELS_FILE.close();
    exit(0);
  }
}

void showMenu() {
  cout << "==================================" << endl;
  cout << "0) Show all hotels" << endl;
  cout << "9) Exit (or another key)" << endl;
  cout << "==================================" << endl;
}

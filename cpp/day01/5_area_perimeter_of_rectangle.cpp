#include <iostream>
using namespace std;

int main() {
  int leftRightSide = 0;
  int topBottomSide = 0;
  cout << "Write a left and right side size of rectangle: ";
  cin >> leftRightSide;
  cout << "Write a top and bottom side size of rectangle: ";
  cin >> topBottomSide;

  int area = leftRightSide * topBottomSide;
  int perimeter = 2 * (leftRightSide + topBottomSide);

  cout << "Rectangle area: " << area << endl;
  cout << "Rectangle perimeter: " << perimeter << endl;
}

#include <iostream>

using namespace std;

int calcRectangleArea(int leftRightSide, int topBottomSide) {
  return leftRightSide * topBottomSide;
}

int calcRectanglePerimeter(int leftRightSide, int topBottomSide) {
  return 2 * (leftRightSide + topBottomSide);
}

int main() {
  int leftRightSide = 0;
  int topBottomSide = 0;

  cout << "Write a left and right side size of rectangle: ";
  cin >> leftRightSide;
  cout << "Write a top and bottom side size of rectangle: ";
  cin >> topBottomSide;

  int area = calcRectangleArea(leftRightSide, topBottomSide);
  int perimeter = calcRectanglePerimeter(leftRightSide, topBottomSide);

  cout << "Rectangle area: " << area << endl;
  cout << "Rectangle perimeter: " << perimeter << endl;

  return 0;
}

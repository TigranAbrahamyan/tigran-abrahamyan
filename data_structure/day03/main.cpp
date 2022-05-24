#include <iostream>
#include "vector.hpp"

int main() {
	Vector<int> vector;
	vector.add(5);
	vector.add(10);
	vector.add(3);
	vector.add(7);
	vector.add(12);
	vector.addFront(108);
	vector.add(54);
	vector.add(123);
	vector.addAt(3, 345);
	vector.removeAt(5);
	vector.removeAt(3);
	vector.add(1000);
	vector.addAt(8, 999);
	std::cout << vector << std::endl;
	std::cout << "Capacity: " << vector.getCapacity() << std::endl;
	std::cout << vector[5] << std::endl;
	std::cout << "Size: " << vector.getSize() << std::endl;

	return 0;
}

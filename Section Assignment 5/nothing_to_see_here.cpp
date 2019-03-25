// CS106B: Programming Abstractions Assignment 5

#include <iostream>
#include <vector>

using namespace std;

struct Car {
	string name;
	int weight;
	int numAirbags;
};

int compareCar(Car a, Car b) {
	if (a.numAirbags > b.numAirbags)
		return 1;
	else if (a.numAirbags < b.numAirbags)
		return -1;
	else if (a.weight > b.weight)
		return 1;
	else if (a.weight < b.weight)
		return -1;
	else
		return 0;
}

template<typename Type>
Type findMax(vector<Type> a, int cmp(Type a, Type b)) {
	Type max = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (cmp(max, a[i]) == -1)
			max = a[i];
	}

	return max;
}

int main() {
	Car test1;
	test1.name = "Toyota Sienna";
	test1.weight = 5;
	test1.numAirbags = 5;

	Car test2;
	test2.name = "Land Rover";
	test2.weight = 7;
	test2.numAirbags = 5;

	Car test3;
	test3.name = "Honda Civic";
	test3.weight = 3;
	test3.numAirbags = 3;

	Car test4;
	test4.name = "Toyota Camry";
	test4.weight = 3;
	test4.numAirbags = 2;

	vector<Car> testCars;
	testCars.push_back(test1);
	testCars.push_back(test2);
	testCars.push_back(test3);
	testCars.push_back(test4);

	cout << findMax(testCars, compareCar).name << endl;
	
	return 0;
}
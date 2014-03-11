// A simple program that computers the square root of a number.

#include <cstdlib>
#include <iostream>
#include <cmath>

int main (int argc, char *argv[]) {
	using namespace std;
	if (argc < 2) {
		cout << "Usage: " << argv[0] << " number" << endl;
		return 1;
	}

	double inputValue = std::atof(argv[1]);
	double outputValue = std::sqrt(inputValue);
	
	cout << "The square root of " << inputValue << " is " << outputValue << endl;

	return 0;
}

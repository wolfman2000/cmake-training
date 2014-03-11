// A simple program that computers the square root of a number.

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.hpp"
#endif

int main (int argc, char *argv[]) {
	using namespace std;
	if (argc < 2) {
        cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR
            << "." << Tutorial_VERSION_MINOR << endl;
		cout << "Usage: " << argv[0] << " number" << endl;
		return 1;
	}

	double inputValue = std::atof(argv[1]);
#ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
#else
    double outputValue = std::sqrt(inputValue);
#endif

	cout << "The square root of " << inputValue << " is " << outputValue << endl;

	return 0;
}

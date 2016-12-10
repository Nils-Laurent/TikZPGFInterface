#include <cstdlib>
#include <ctime>
#include <iostream>

namespace {
	using namespace std;

	double getDouble(double min, double max) {
		double y = static_cast<double>(rand() % (static_cast<int>(max)+1))+min;

		if ( y > max ) {
			int coef = (y - min) / (max - min);
			return (y - coef*(max - min));
		}

		return y;
	}
}

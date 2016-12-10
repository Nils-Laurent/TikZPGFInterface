#include "metatest.h"
#include "coordinates.h"
#include <iostream>
#include <vector>

namespace {

	using namespace std;

	void testCoordDouble(double xa, double xb, double ya, double yb, size_t num) {
		typedef TikZPGFgen::Coordinates<double, double> tCoord;

		double step = (xb - xa)/num;
		double prev = xa;
		vector<tCoord> coords;
		for (unsigned int i = 0; i < num; ++i) {
			coords.push_back({
					getDouble(prev, prev+step),
					getDouble(ya, yb)});
			prev = coords[i].x+step;
			cout << " x " << coords[i].x << " y " << coords[i].y << endl;
		}

		TikZPGFgen::DocSpecs ds;
		ds.xName = "ghz";
		ds.yName = "sec";
		TikZPGFgen::CurveSpecs cs;
		cs.name = "Toto";

		TikZPGFgen::writeCoords<double, double>(ds, &coords, &cs, 1);
	}
}

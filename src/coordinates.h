#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <iostream>

#include "tikzpgf.h"

#define COORD Coordinates<x_t, y_t>

namespace TikZPGFgen {
	
	using namespace std;

	string g_fprefix = "\\begin{tikzpicture}\n  \\draw plot coordinates{";
	string g_fsuffix = "};\n\\end{tikzpicture}";

	template<typename x_t, typename y_t>
	struct Coordinates {
		x_t x;
		y_t y;
	};

	struct DocSpecs{

		DocSpecs() :
			title("noname"), xDivider(1), yDivider(1), autofit(true)
		{}

		string title;
		string xName;
		string yName;
		double xDivider;
		double yDivider;
		bool autofit;
		double minX;
		double maxX;
		double minY;
		double maxY;
	};

	
	struct CurveSpecs{

		CurveSpecs () :
			color(Black)
		{}

		string name;
		Color color;
		string description;
	};

	struct _dCoord {
		double x;
		double y;
	};

	typedef vector<_dCoord> curve_t;

	void writeFigureStart(ofstream& ofs);
	void writeTPictureStart(ofstream& ofs, DocSpecs ds);
	void writeCurve(ofstream& ofs, CurveSpecs cs, string coords);
	void writeTPictureEnd(ofstream& ofs, DocSpecs ds);
	void writeDescriptionStart(ofstream& ofs);
	void writeCurveDescription(ofstream& ofs, CurveSpecs cs);
	void writeDescriptionEnd(ofstream& ofs);
	void writeFigureEnd(ofstream& ofs);

	template<typename x_t, typename y_t>
	curve_t _resize(double xDivider, double yDivider, vector<COORD> const& userData) {
		curve_t result;
		for(COORD const& c : userData) {
			result.push_back({
					static_cast<double>(c.x/xDivider),
					static_cast<double>(c.y/yDivider)});
		}

		return result;
	}

	string curveToStr(curve_t const& c) {
		string coords = "";

		for (_dCoord const& dc : c)
			coords += " (" + to_string(dc.x) + ", " + to_string(dc.y) + ")";

		return coords;
	}

	template<typename x_t, typename y_t>
	void writeCoords(DocSpecs ds, vector<COORD>* userCoords, CurveSpecs* p_cs, size_t curveNumber) {
		if (ds.xName.size() == 0 && ds.yName.size() == 0) {
			cout << "Axes names not defined for document " << ds.title << endl;
			return;
		}
	
		for (unsigned int curveIndex = 0; curveIndex < curveNumber; ++curveIndex) {
			if (p_cs[curveIndex].name.size() == 0)
				cout << "Curve at index [" << curveIndex << "] has no name" << endl;
		}
		
		ofstream ofs(ds.title + ".tex", ios::out | ios::trunc);
		if (! ofs.is_open()) {
			cout << "ofstream, could not write into : " << ds.title << ".tex" << endl;
		}

		writeFigureStart(ofs);
		writeTPictureStart(ofs, ds);
		
		for (unsigned int curveIndex = 0; curveIndex < curveNumber; ++curveIndex) {
			curve_t curve = _resize<x_t, y_t>(ds.xDivider, ds.yDivider, userCoords[curveIndex]);
			string strCoords = curveToStr(curve);
			writeCurve(ofs, p_cs[curveIndex], strCoords);
		}
		
		writeTPictureEnd(ofs, ds);
		writeDescriptionStart(ofs);
		for (unsigned int curveIndex = 0; curveIndex < curveNumber; ++curveIndex) {
			writeCurveDescription(ofs, p_cs[curveIndex]);
		}

		writeDescriptionEnd(ofs);
		writeFigureEnd(ofs);

		ofs.close();
	}

	void writeFigureStart(ofstream& ofs) {
		ofs << g_bFig << endl;
		ofs << g_center << endl;
	}

	void writeTPictureStart(ofstream& ofs, DocSpecs ds) {
		ofs << g_bTPicture << endl;
		ofs << g_bAxis << endl;
		stringstream ss;
		if (ds.autofit) {
			ofs << renderAxisOpts(ds.xName, ds.yName);
		} else {
			ofs << renderAxisOpts(to_string(ds.minX), to_string(ds.maxX),
					to_string(ds.minY), to_string(ds.maxY),
					ds.xName, ds.yName);
		}
	}

	void writeCurve(ofstream& ofs, CurveSpecs cs, string coords) {
		ofs << renderPlot(XColors::s_map[cs.color], coords);
	}
	
	void writeTPictureEnd(ofstream& ofs, DocSpecs ds) {
		ofs << g_eAxis << endl;
		ofs << g_eTPicture << endl;
		ofs << renderCaption(ds.title);
	}

	void writeDescriptionStart(ofstream& ofs) {
		ofs << g_bCenter << endl;
	}

	void writeCurveDescription(ofstream& ofs, CurveSpecs cs) {
		ofs << renderTextColor(XColors::s_map[cs.color], cs.description);
	}

	void writeDescriptionEnd(ofstream& ofs) {
		ofs << g_eCenter << endl;
	}

	void writeFigureEnd(ofstream& ofs) {
		ofs << g_eFig << endl;
	}
}

#include <string>
#include <map>

namespace TikZPGFgen {
	using namespace std;

	string g_bFig = "\\begin{figure}";
	string g_eFig = "\\end{figure}";
	string g_center = "\\center";
	string g_bTPicture = "\\begin{tikzpicture}";
	string g_eTPicture = "\\end{tikzpicture}";
	string g_bAxis = "\\begin{axis}";
	string g_eAxis = "\\end{axis}";
	string g_bCenter = "\\begin{center}";
	string g_eCenter = "\\end{center}";

	string renderCaption(string title) {
		return "\\caption{"+title+"}\n";
	};
	string renderPlot(string color, string coords) {
		return "\\addplot ["+color+"] coordinates\n"
			+"{"+coords+"};\n";
	};
	string renderTextColor(string color, string text) {
		return "\\textcolor{"+color+"}{"+text+"}\\par\n";
	};
	string renderAxisOpts(string xmin, string xmax,
			string ymin, string ymax,
			string xlabel, string ylabel) {
		string result = "[\n";
		result += "xmin="+xmin+", xmax="+xmax+",\n";
		result += "ymin="+ymin+", ymax="+ymax+",\n";
		result += "xlabel="+xlabel+", ylabel="+ylabel+",\n";
		result += "]\n";
		
		return result;
	};
	string renderAxisOpts(string xlabel, string ylabel) {
		string result = "[\n";
		result += "xlabel="+xlabel+", ylabel="+ylabel+",\n";
		result += "]\n";

		return result;
	};

// xcolor colors
	enum Color {
		White,
		Black,

		GreenYellow,
		Yellow,
		Goldenrod,
		Dandelion,
		Apricot,
		Peach,
		Melon,
		YellowOrange,

		Orange,
		BurntOrange,
		Bittersweet,
		RedOrange,
		Mahogany,
		Maroon,
		BrickRed,
		Red,

		OrangeRed,
		RubineRed,
		WildStrawberry,
		Salmon,
		CarnationPink,
		Magenta,
		VioletRed,
		Rhodamine,

		Mulberry,
		RedViolet,
		Fuchsia,
		Lavender,
		Thistle,
		Orchid,
		DarkOrchid,
		Purple,

		Plum,
		Violet,
		RoyalPurple,
		BlueViolet,
		Periwinkle,
		CadetBlue,
		CornflowerBlue,
		MidnightBlue,

		NavyBlue,
		RoyalBlue,
		Blue,
		Cerulean,
		Cyan,
		ProcessBlue,
		SkyBlue,
		Turquoise,

		TealBlue,
		Aquamarine,
		BlueGreen,
		Emerald,
		JungleGreen,
		SeaGreen,
		Green,
		ForestGreen,

		PineGreen,
		LimeGreen,
		YellowGreen,
		SpringGreen,
		OliveGreen,
		RawSienna,
		Sepia,
		Brown,
		Tan,
	};


	struct XColors {
		static map<Color, string> getXCM() {
			map<Color, string> tmp;


			tmp[White]= "White";
			tmp[Black]= "Black";

			tmp[GreenYellow]= "GreenYellow";
			tmp[Yellow]= "Yellow";
			tmp[Goldenrod]= "Goldenrod";
			tmp[Dandelion]= "Dandelion";
			tmp[Apricot]= "Apricot";
			tmp[Peach]= "Peach";
			tmp[Melon]= "Melon";
			tmp[YellowOrange]= "YellowOrange";

			tmp[Orange]= "Orange";
			tmp[BurntOrange]= "BurntOrange";
			tmp[Bittersweet]= "Bittersweet";
			tmp[RedOrange]= "RedOrange";
			tmp[Mahogany]= "Mahogany";
			tmp[Maroon]= "Maroon";
			tmp[BrickRed]= "BrickRed";
			tmp[Red]= "Red";

			tmp[OrangeRed]= "OrangeRed";
			tmp[RubineRed]= "RubineRed";
			tmp[WildStrawberry]= "WildStrawberry";
			tmp[Salmon]= "Salmon";
			tmp[CarnationPink]= "CarnationPink";
			tmp[Magenta]= "Magenta";
			tmp[VioletRed]= "VioletRed";
			tmp[Rhodamine]= "Rhodamine";

			tmp[Mulberry]= "Mulberry";
			tmp[RedViolet]= "RedViolet";
			tmp[Fuchsia]= "Fuchsia";
			tmp[Lavender]= "Lavender";
			tmp[Thistle]= "Thistle";
			tmp[Orchid]= "Orchid";
			tmp[DarkOrchid]= "DarkOrchid";
			tmp[Purple]= "Purple";

			tmp[Plum]= "Plum";
			tmp[Violet]= "Violet";
			tmp[RoyalPurple]= "RoyalPurple";
			tmp[BlueViolet]= "BlueViolet";
			tmp[Periwinkle]= "Periwinkle";
			tmp[CadetBlue]= "CadetBlue";
			tmp[CornflowerBlue]= "CornflowerBlue";
			tmp[MidnightBlue]= "MidnightBlue";

			tmp[NavyBlue]= "NavyBlue";
			tmp[RoyalBlue]= "RoyalBlue";
			tmp[Blue]= "Blue";
			tmp[Cerulean]= "Cerulean";
			tmp[Cyan]= "Cyan";
			tmp[ProcessBlue]= "ProcessBlue";
			tmp[SkyBlue]= "SkyBlue";
			tmp[Turquoise]= "Turquoise";

			tmp[TealBlue]= "TealBlue";
			tmp[Aquamarine]= "Aquamarine";
			tmp[BlueGreen]= "BlueGreen";
			tmp[Emerald]= "Emerald";
			tmp[JungleGreen]= "JungleGreen";
			tmp[SeaGreen]= "SeaGreen";
			tmp[Green]= "Green";
			tmp[ForestGreen]= "ForestGreen";

			tmp[PineGreen]= "PineGreen";
			tmp[LimeGreen]= "LimeGreen";
			tmp[YellowGreen]= "YellowGreen";
			tmp[SpringGreen]= "SpringGreen";
			tmp[OliveGreen]= "OliveGreen";
			tmp[RawSienna]= "RawSienna";
			tmp[Sepia]= "Sepia";
			tmp[Brown]= "Brown";
			tmp[Tan]= "Tan";

			return tmp;
		}

		static map<Color, string> s_map;
	};

	map<Color, string> XColors::s_map = XColors::getXCM();
}

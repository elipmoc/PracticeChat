#include "M_Font.h"

namespace experiment {
	namespace ATH {
		siv::Font MakeFont(siv::FontStyle kind, int FontSize) {
			return siv::Font(FontSize, siv::Typeface::Default, kind);
		}

		/*siv::Font M_Font::MakeFont(siv::FontStyle kind, int FontSize) {
			siv::Font f;
			if (kind == 0) f = siv::Font(FontSize);
			else if (kind == 1) f = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Bold);
			else if (kind == 2) f = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Italic);
			else if (kind == 3) f = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::BoldItalic);
			return siv::Font(FontSize,siv::Typeface::Default,kind);
		}
		*/
		/*
		void FontManager::setFontsize(int kind, int FontSize)
		{
		_makeFont(kind, FontSize);
		}
		*/

		M_Font::M_Font()
		{
			// for (int i = 0; i < 4; i++) _makeFont(24, i);
		}

		M_Font::~M_Font()
		{
		}
	}
}
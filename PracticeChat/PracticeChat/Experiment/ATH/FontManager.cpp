#include "FontManager.h"


namespace experiment {
	namespace ATH {
		siv::Font FontManager::makeFont(int ftp, int FontSize) {
			siv::Font font;
			if (ftp == 0) font = siv::Font(FontSize);
			if (ftp == 1) font = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Bold);
			if (ftp == 2) font = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Italic);
			if (ftp == 3) font = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::BoldItalic);
			return font;
		}

		/*
		void FontManager::setFontsize(int ftp, int FontSize)
		{
			makeFont(ftp, FontSize);
		}

		FontManager::FontManager()
		{
			for (int i = 0; i < 4; i++) makeFont(24, i);
		}
		*/

		FontManager::~FontManager()
		{
		}
	}
}
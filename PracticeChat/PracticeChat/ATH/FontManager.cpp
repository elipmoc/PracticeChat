#include "FontManager.h"


namespace ATH {
	void FontManager::_makeFont(int ftp, int FontSize) {
		if (ftp == 0) f[0] = siv::Font(FontSize);
		if (ftp == 1) f[1] = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Bold);
		if (ftp == 2) f[2] = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Italic);
		if (ftp == 3) f[3] = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::BoldItalic);
	}

	void FontManager::setFontsize(int ftp, int FontSize)
	{
		_makeFont(ftp, FontSize);
	}

	FontManager::FontManager()
	{
		for (int i = 0; i < 4; i++) _makeFont(24,i);
	}

	FontManager::~FontManager()
	{
	}
}
#include "FontManager.h"


namespace experiment {
	namespace ATH {

	void FontManager::_makeFont(int kind, int FontSize) {
		if (kind == 0) f[0] = siv::Font(FontSize);
		if (kind == 1) f[1] = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Bold);
		if (kind == 2) f[2] = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::Italic);
		if (kind == 3) f[3] = siv::Font(FontSize, s3d::Typeface::Default, s3d::FontStyle::BoldItalic);
	}

	void FontManager::setFontsize(int kind, int FontSize)
	{
		_makeFont(kind, FontSize);
	}

	FontManager::FontManager()
	{
		for (int i = 0; i < 4; i++) _makeFont(24, i);
	}

	FontManager::~FontManager()
	{
	}
}
}
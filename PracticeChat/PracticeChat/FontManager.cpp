#include "FontManager.h"



void FontManager::setFontsize(FontTypePattern ftp, int FontSize)
{
}

FontManager::FontManager()
{
	f[0] = siv::Font(30); // normal
	f[1] = siv::Font(30, siv::Typeface::Default, siv::FontStyle::Italic ); // italic
	f[2] = siv::Font(30, siv::Typeface::Default, siv::FontStyle::Bold); // bold
	f[3] = siv::Font(30, siv::Typeface::Default, siv::FontStyle::BoldItalic); // bolditalic
	f[0](L"hogehoge").draw(200, 50);
}

FontManager::~FontManager()
{
}

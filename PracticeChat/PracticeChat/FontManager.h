#pragma once
//
class FontManager
{
	siv::Font f[4];
public:
	enum FontTypePattern {
		Normal,
		Italic,
		Bold,
		BoldItalic
	};
	void setFontsize(FontTypePattern ftp,int FontSize);
	FontManager();
	~FontManager();
};
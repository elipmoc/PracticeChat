#include "Text.h"
#include "M_Font.h"

namespace experiment {
	namespace ATH {
		Text::Text(const siv::String& _text, int _fontSize, int _fontPattern, int _drawX, int _drawY, const siv::Color& _color)
		{
			text = _text;
			fontSize = _fontSize;
			fontPattern = _fontPattern;
			drawX = _drawX;
			drawY = _drawY;
			font = experiment::ATH::M_Font::MakeFont(fontPattern, fontSize);
		}

		void Text::Update()
		{
		}
		
		void Text::Draw()
		{
			font(text).draw(drawX, drawY, color);
		}

		void Text::SetFontsize(int fontSize) noexcept {
			font = experiment::ATH::M_Font::MakeFont(fontPattern, fontSize);
		}

		void Text::SetColor(const siv::Color& _color) noexcept
		{
			color = _color;
		}

		Text::~Text()
		{
		}
	}
}
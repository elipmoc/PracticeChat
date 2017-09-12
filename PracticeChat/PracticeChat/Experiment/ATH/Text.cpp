#include "Text.h"
#include "M_Font.h"

namespace experiment {
	namespace ATH {
		Text::Text(const siv::String& _text, int _fontSize, siv::FontStyle _fontStyle, int _drawX, int _drawY, const siv::Color& _color)
		{
			text = _text;
			fontSize = _fontSize;
			fontStyle = _fontStyle;
			drawX = _drawX;
			drawY = _drawY;
			color = _color;
			font = experiment::ATH::MakeFont(fontStyle, fontSize);
		}

		void Text::Update()
		{
		}
		
		void Text::Draw()
		{
			font(text).draw(drawX, drawY,color);
		}

		void Text::SetFontsize(int fontSize) noexcept {
			font = experiment::ATH::MakeFont(fontStyle ,fontSize);
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
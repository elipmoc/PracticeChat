#pragma once
namespace experiment {
	namespace ATH {
		class Text
		{
			s3d::Font font;
			s3d::String text;
			int drawX, drawY; // é¿ç€Ç… draw Ç∑ÇÈ
			siv::FontStyle fontStyle;
			int fontSize;
			siv::Color color;

			Text();
		public:
			/*
			Text(int fontSize);
			// Text(int fontSize, s3d::Typeface tf, s3d::FontStyle fs);
			Text(int fontSize, int fontPattern);
			Text(int fontSize, int fontPattern, int _drawX, int _drawY, siv::Color color);
			Text(int fontSize, int fontPattern, int _drawX, int _drawY);
			*/
			Text(
				const siv::String& _text,
				int _fontSize = 24, 
				siv::FontStyle _fontStyle = siv::FontStyle::Regular,
				int _drawX = 0, 
				int _drawY = 0,
				const siv::Color& _color = siv::Palette::White
			);
			void SetPos(int _drawx, int _drawy) noexcept{
				drawX = _drawx;
				drawY = _drawy;
			}
			void Update();
			void Draw();
			void SetFontsize(int fontSize) noexcept;
			void SetColor(const siv::Color& color) noexcept; // siv::Palette::Lightgreen
			void End(){}

			~Text();
		};
	}
}


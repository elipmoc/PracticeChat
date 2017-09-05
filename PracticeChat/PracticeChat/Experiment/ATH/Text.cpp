#include "Text.h"


namespace experiment {
	namespace ATH {
		Text::Text()
		{
		}

		Text::Text(int fontSize){
			// font = s3d::Font(fontSize);
		}
		Text::Text(int fontSize, s3d::Typeface tf, s3d::FontStyle fs)
		{
			// font = siv::Font(fontSize, tf, fs);
		}
		Text::Text(int fontSize, int fontPattern)
		{
			// font = FontManager::makeFont(fontSize, fontPattern);
		}

		void Text::Update(){}
		void Text::End(){}

		Text::~Text()
		{
		}
	}
}
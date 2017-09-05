#pragma once
namespace experiment {
	namespace ATH {
		class Text
		{
			s3d::Font font;
		public:
			int posX, posY;

			Text();
			Text(int fontSize);
			Text(int fontSize, s3d::Typeface tf, s3d::FontStyle fs);
			Text(int fontSize, int fontPattern);

			void Update();
			void End();

			~Text();
		};
	}
}


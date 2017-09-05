#pragma once

namespace experiment {
	namespace ATH {
		// 0 = ノーマルテキスト
		// 1 = ボールドテキスト
		// 2 = イタリックテキスト
		// 3 = ボールドイタリック

		/* ファクトリパターンっぽくする */
		class FontManager
		{
		public:
			siv::Font static makeFont(int kind, int fontsize);

			/*
			void setFontsize(int kind, int FontSize);
			FontManager();
			*/

			~FontManager();
		};
	}
}
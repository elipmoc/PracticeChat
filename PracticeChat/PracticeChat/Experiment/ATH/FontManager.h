#pragma once

namespace experiment {
	namespace ATH {
		// 0 = ノーマルテキスト
		// 1 = ボールドテキスト
		// 2 = イタリックテキスト
		// 3 = ボールドイタリック

		class FontManager
		{
			void _makeFont(int kind, int fontsize);
		public:
			siv::Font f[4];
			void setFontsize(int kind, int FontSize);
			FontManager();
			~FontManager();
		};
	}
}
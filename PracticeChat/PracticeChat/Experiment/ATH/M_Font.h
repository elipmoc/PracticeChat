#pragma once

namespace experiment {
	namespace ATH {
		siv::Font MakeFont(siv::FontStyle kind, int fontsize);
		class M_Font
		{
			// 0 = ノーマルテキスト
			// 1 = ボールドテキスト
			// 2 = イタリックテキスト
			// 3 = ボールドイタリック
		public:
		//	static siv::Font MakeFont(siv::FontStyle kind, int fontsize);
			M_Font();
			~M_Font();
		};
	}
}
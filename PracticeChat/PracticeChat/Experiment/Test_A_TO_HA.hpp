#pragma once
#include "ATH\M_Font.h"
#include "ATH\Text.h"
#include <memory>

namespace experiment {
	class Test_A_TO_HA {
		std::unique_ptr<ATH::Text> text;
		ATH::M_Font fm;
		int fontsize = 16;
		int frame = 0;
	public:
		void Init() {
			text = std::make_unique<ATH::Text>(L"名前スペース！",30, 1);
			text->SetColor({ 255,127,0 });
		}
		void Update(){
			frame++; frame %= 10;
			if (frame == 0) {
				fontsize++;
				if (fontsize > 60) fontsize = 16;
				for (int i = 0; i < 4; i++) text->SetFontsize(fontsize);
			}

			text->Draw();
		}
		void End(){}
	};
}
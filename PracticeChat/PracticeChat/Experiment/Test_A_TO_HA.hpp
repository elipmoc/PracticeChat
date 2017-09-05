#pragma once
#include "ATH\FontManager.h"

namespace experiment {
	class Test_A_TO_HA {
		ATH::FontManager fm;
		int fontsize = 16;
		int frame = 0;
	public:
		void Init(){	
			siv::Println(L"OK");
		}
		void Update(){
			/*
			frame++; frame %= 10;
			if (frame == 0) {
				fontsize++;
				if (fontsize > 60) fontsize = 16;
				for (int i = 0; i < 4; i++) fm.setFontsize(i, fontsize);
			}
			fm.f[0](L"ネーム空間はタブー").draw(10,10);
			fm.f[1](L"ネーム空間はタブー").draw(10,60);
			fm.f[2](L"ネーム空間はタブー").draw(10,110);
			fm.f[3](L"ネーム空間はタブー").draw(10,160);
			*/
		}
		void End(){}
	};
}
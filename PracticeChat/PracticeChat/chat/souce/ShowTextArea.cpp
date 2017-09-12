#include "../header/ShowTextArea.hpp"
#include "../../Experiment/ATH/Text.h"

namespace chat{
	ShowTextArea::ShowTextArea()
		:text(std::make_unique<Text>(L"‚±‚ê‚Í‚Ä‚·‚Æ‚Å‚·",30,siv::FontStyle::Italic,0,0,siv::Palette::Black))
	{
	}
	ShowTextArea::~ShowTextArea()
	{
	}
	void ShowTextArea::Update()
	{
	}
	void ShowTextArea::Draw() const
	{
		text->Draw();
	}
}
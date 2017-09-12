#include "../header/ShowTextArea.hpp"
#include "../../Experiment/ATH/Text.h"


namespace chat{
	ShowTextArea::ShowTextArea()
		:text(std::make_unique<Text>(L"これはてすとです",30,siv::FontStyle::Italic,0,0,siv::Palette::White))
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
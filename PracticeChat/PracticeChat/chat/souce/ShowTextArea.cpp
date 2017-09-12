#include "../header/ShowTextArea.hpp"
#include "../../Experiment/ATH/Text.h"


namespace chat{
	GUIChatArea::GUIChatArea(const s3d::String& label, const siv::WidgetStyle& style)
		:text(std::make_unique<Text>(L"‚±‚ê‚Í‚Ä‚·‚Æ‚Å‚·",30,siv::FontStyle::Italic,50,50,siv::Palette::Black)),
		name(label)
	{
	}
	GUIChatArea::~GUIChatArea()
	{
	}
	void GUIChatArea::update(const siv::WidgetState& state)
	{
	}
	void GUIChatArea::draw(const siv::WidgetState& state) const
	{
		text->Draw();
	}
}
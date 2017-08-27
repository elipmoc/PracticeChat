#include "FontExperiment.h"



FontExperiment::FontExperiment()
{
}


FontExperiment::~FontExperiment()
{
}

int FontExperiment::MainLoop()
{
	const siv::Font font(30);
	siv::Font font2(30, siv::Typeface::Bold, siv::FontStyle::Italic );
	siv::Font font3(30, siv::Typeface::Default, siv::FontStyle::BoldItalic);
	while (siv::System::Update())
	{
		font(L"ようこそ、真のGithub の世界へ！").draw(20,20);
		font2(L"ようこそ、真のGithub の世界へ！").draw(20, 170);
		font3(L"ようこそ、真のGithub の世界へ！").draw(20, 320);
		siv::Circle(siv::Mouse::Pos(), 100).draw({ 127, 127, 127, 127 });
		siv::Circle(siv::Mouse::Pos(), 70).draw({ 255, 255, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 20).draw({ 0, 127, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 10).draw({ 0, 0, 127, 127 });
	}
	return 1;
}

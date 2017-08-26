#include "UseSiv3D.hpp"

void Main()
{
	const siv::Font font(30);

	while (siv::System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();

		siv::Circle(siv::Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}

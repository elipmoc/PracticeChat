

void Main()
{

	const siv::Font font(30);

	while (siv::System::Update())
	{
		font(L"ようこそ、真のGithub の世界へ！").draw();
		siv::Circle(siv::Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 20).draw({ 0, 127, 0, 127 });
		siv::Circle(siv::Mouse::Pos(), 10).draw({ 0, 0, 127, 127 });
	}
}

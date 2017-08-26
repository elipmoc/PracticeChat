

void Main()
{
	const siv::Font font(30);

	while (siv::System::Update())
	{
		// 20170827_ATH.
		font(L"ようこそ、真のGithub の世界へ！").draw();

		siv::Circle(siv::Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}

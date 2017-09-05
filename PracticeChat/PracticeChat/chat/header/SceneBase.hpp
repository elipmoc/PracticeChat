#pragma once

namespace chat {
	//シーン間で共有するデータ
	struct ShareGameData {
		siv::String userName;
		siv::String ipAddress;
		siv::String portNumber;
		siv::Font font{ 10 };
	};

	//シーン操作クラス
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//シーンの基底クラス
	using MySceneBase = MySceneManager::Scene;
}
#pragma once
#include <memory>

namespace experiment {
	namespace ATH {
		class Text;
	}
}

namespace chat {
	using experiment::ATH::Text;

	class ShowTextArea {
		std::unique_ptr<Text> text;
	public:
		ShowTextArea();
		~ShowTextArea();
		void Update();
		void Draw()const;
	};
}
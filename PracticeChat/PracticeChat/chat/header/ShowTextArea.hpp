#pragma once
#include <memory>

namespace experiment {
	namespace ATH {
		class Text;
	}
}

namespace chat {
	using experiment::ATH::Text;

	class GUIChatArea :public siv::IWidget{
		std::unique_ptr<Text> text;
		siv::String name;
	public:
		static std::shared_ptr<GUIChatArea> Create(const s3d::String& label, const siv::WidgetStyle& style = siv::WidgetStyle())
		{
			return std::make_shared<GUIChatArea>(label, style);
		}
		virtual bool forceNewLineBefore()const override { return false; };
		virtual bool forceNewLineAfter()const override { return false; };
		virtual const siv::String& getWidgetName() const override {
			return name;
		}

		virtual siv::Size getSize() const override {
			return{ 50,50 };
		}

		virtual void update(const siv::WidgetState& state) override;

		virtual void draw(const siv::WidgetState& state) const override;
		GUIChatArea(const s3d::String& label, const siv::WidgetStyle& style);
		~GUIChatArea();
	};
}
#pragma once
#include <functional>
#include <memory>

namespace Component
{
	class Button
	{
		using Listener = std::function<void()>;

	public:
		Button();
		~Button();

		void attachListener(Listener listener);
		void click();

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
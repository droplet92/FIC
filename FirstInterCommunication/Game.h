#pragma once
#include <memory>

namespace FIC
{
	class Game
	{
	public:
		Game();
		~Game();

		void run();
		void update();
		void draw();

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
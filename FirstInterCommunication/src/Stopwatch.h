#pragma once
#include "Time.h"
#include <memory>

namespace Time
{
	class Stopwatch
	{
	public:
		Stopwatch();
		~Stopwatch();

		void start();
		time_ms stop();
		void clear();

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
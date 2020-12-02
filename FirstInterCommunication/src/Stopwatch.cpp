#include "Stopwatch.h"
#include <chrono>
using namespace std::chrono;

namespace Time
{
	struct Stopwatch::Impl
	{
		high_resolution_clock::time_point stopwatch_start;
		high_resolution_clock::time_point stopwatch_end;

	};

	Stopwatch::Stopwatch()
		: pImpl(new Impl)
	{
		clear();
	}

	Stopwatch::~Stopwatch() = default;

	void Stopwatch::start()
	{
		pImpl->stopwatch_start = high_resolution_clock::now();
	}

	time_ms Stopwatch::stop()
	{
		pImpl->stopwatch_end = high_resolution_clock::now();
		return (pImpl->stopwatch_end - pImpl->stopwatch_start).count();
	}

	void Stopwatch::clear()
	{
		pImpl->stopwatch_start = pImpl->stopwatch_end = high_resolution_clock::now();
	}
}
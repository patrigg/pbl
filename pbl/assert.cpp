#include "assert.h"
#include <iostream>

namespace pbl
{

	namespace {
		void defaultAssertionHandler(const char* file, int line, const char* function, const char* condition, const char* message)
		{
			std::cerr << message << std::endl << "\tExpression: " << condition << std::endl << "\tIn: (" << file << "," << line << ") " << function << std::endl;
			__debugbreak();
		}

		AssertionHandler assertionHandler(defaultAssertionHandler);
	}

	void failedAssert(const char* file, int line, const char* function, const char* condition, const char* message)
	{
		if (assertionHandler)
			assertionHandler(file, line, function, condition, message);
	}

	void setAssertionHandler(AssertionHandler handler)
	{
		assertionHandler = handler;
	}
	void clearAssertionHandler()
	{
		assertionHandler = nullptr;
	}
}
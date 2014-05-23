#pragma once
#include <functional>
#include <string>

namespace pbl
{
#define PBL_CAT(A, B) A ## B

#define PBL_GET_COUNT( _1, _2, _3, _4, _5, _6, _7, _8, _9, COUNT, ... ) COUNT
#define PBL_VA_SIZE( ... ) PBL_GET_COUNT( __VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1 )

	/// Concatenates two strings, even when the strings are macros themselves
#define PBL_CONCAT(x,y) PBL_CONCAT_HELPER(x,y)
#define PBL_CONCAT_HELPER(x,y) PBL_CONCAT_HELPER2(x,y)
#define PBL_CONCAT_HELPER2(x,y) x##y

#define PBL_SELECT(NAME, NUM) PBL_CONCAT(NAME ## _, NUM)

#define PBL_VA_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define PBL_VA_NUM_ARGS_REVERSE_SEQUENCE 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
#define PBL_LEFT_PARENTHESIS (
#define PBL_RIGHT_PARENTHESIS )
#define PBL_VA_NUM_ARGS(...) PBL_VA_NUM_ARGS_HELPER PBL_LEFT_PARENTHESIS __VA_ARGS__, PBL_VA_NUM_ARGS_REVERSE_SEQUENCE PBL_RIGHT_PARENTHESIS
#define PBL_PASS_VA(...)                            PBL_LEFT_PARENTHESIS __VA_ARGS__ PBL_RIGHT_PARENTHESIS

#define PBL_VA_SELECT( NAME, ... ) PBL_SELECT( NAME, PBL_VA_NUM_ARGS(__VA_ARGS__) )PBL_PASS_VA(__VA_ARGS__)

	typedef std::function < void(const char*, int, const char*, const char *, const char*)> AssertionHandler;

	void failedAssert(const char* file, int line, const char* function, const char* condition, const char* message);

#define PBL_ASSERT_1(cond) \
	if (!(cond)) { pbl::failedAssert(__FILE__, __LINE__, __FUNCTION__, #cond, "Assertion failed!"); }

#define PBL_ASSERT_2(cond, message) \
	if (!(cond)) { pbl::failedAssert(__FILE__, __LINE__, __FUNCTION__, #cond, message); }

#if defined(_DEBUG) || defined(UNITTESTS)
#define PBL_ASSERT(...) PBL_VA_SELECT(PBL_ASSERT, __VA_ARGS__)
#else
#define PBL_ASSERT(...)
#endif

	void setAssertionHandler(AssertionHandler handler);
	void clearAssertionHandler();
}
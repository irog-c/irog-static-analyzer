#include <analyzer.hpp>

#include <iostream>

auto foo() -> int
{
	std::cout << "foo called\n";
	return 0;
}

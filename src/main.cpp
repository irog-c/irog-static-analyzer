#include <checker_frontend_action.hpp>

#include <clang/Tooling/Tooling.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

auto main(const int argc, const char* argv[]) -> int
{
	if (argc < 2) {
		std::cerr << "Bad input, file required\nUsage: " << argv[0] << " <file name>\n";
		return EXIT_FAILURE;
	}

	auto file_path = std::string(argv[1]);
	auto file_in = std::fstream(file_path);
	if (not file_in.is_open()) {
		std::cerr << "Failed to open file " << file_path << '\n';
		return EXIT_FAILURE;
	}

	auto file_contents = std::string((std::istreambuf_iterator<char>(file_in)),
	    (std::istreambuf_iterator<char>()));

	auto action = std::make_unique<CheckerFrontendAction>();
	clang::tooling::runToolOnCode(std::move(action), file_contents, file_path);
	return EXIT_SUCCESS;
}

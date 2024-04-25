#pragma once

#include <checker_ast_consumer.hpp>

#include <clang/Frontend/FrontendAction.h>

#include <memory>

class CheckerFrontendAction : public clang::ASTFrontendAction {
    public:
	auto CreateASTConsumer(clang::CompilerInstance& CI, llvm::StringRef InFile)
	    -> std::unique_ptr<clang::ASTConsumer> override
	{
		return std::make_unique<CheckerASTConsumer>();
	}
};

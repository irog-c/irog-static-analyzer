#pragma once

#include <checker_ast_visitor.hpp>

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>

class CheckerASTConsumer : public clang::ASTConsumer {
    public:
	auto HandleTranslationUnit(clang::ASTContext& context) -> void override
	{
		CheckerASTVisitor visitor;
		visitor.TraverseDecl(context.getTranslationUnitDecl());
	}
};

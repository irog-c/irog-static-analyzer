#pragma once

#include <clang/AST/RecursiveASTVisitor.h>

class CheckerASTVisitor : public clang::RecursiveASTVisitor<CheckerASTVisitor> {
    public:
	auto VisitFunctionDecl(clang::FunctionDecl* f) -> bool
	{
		const auto name = f->getNameAsString();
		if (name.find("_") != std::string::npos) {
			auto& DE = f->getASTContext().getDiagnostics();
			auto diagID = DE.getCustomDiagID(
			    clang::DiagnosticsEngine::Error,
			    "Function name contains `_`.");
			DE.Report(f->getLocation(), diagID);
		}
		return true;
	}
};

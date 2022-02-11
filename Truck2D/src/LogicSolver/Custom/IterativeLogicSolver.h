#pragma once
#include <LogicSolver/ILogicSolver.h>

class IterativeLogicSolver : public ILogicSolver
{
public:
	IterativeLogicSolver() = default;
	~IterativeLogicSolver() = default;

	virtual void Solve(Array<Component*>& components, float deltaTime) override;
};
#pragma once
#include <LogicSolver/ILogicSolver.h>

/// <summary>
/// Simple custom logic solver implementation
/// Iterates all the logic components and procs their virtual functions
/// </summary>
class IterativeLogicSolver : public ILogicSolver
{
public:
	IterativeLogicSolver() = default;
	~IterativeLogicSolver() = default;

	virtual void Solve(Array<Component*>& components, float deltaTime) override;
};
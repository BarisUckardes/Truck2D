#pragma once

template<typename TElement>
class Array;

class Component;

/// <summary>
/// Interface for all logic resolvers to implement
/// </summary>
class ILogicSolver
{
public:
	ILogicSolver() = default;
	~ILogicSolver() = default;

	/// <summary>
	/// Solves the logics by calling the derived class implementation
	/// </summary>
	virtual void Solve(Array<Component*>& components, float deltaTime) = 0;
};
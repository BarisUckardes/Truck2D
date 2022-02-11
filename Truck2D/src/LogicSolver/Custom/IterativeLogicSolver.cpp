#include "IterativeLogicSolver.h"
#include <Memory/Array.h>
#include <World/Component.h>
void IterativeLogicSolver::Solve(Array<Component*>& components, float deltaTime)
{
	/*
	* Iterate and simply proc
	*/
	for (unsigned int i = 0; i < components.GetCursor(); i++)
	{
		components[i]->OnTick(deltaTime);
	}
}

#include "Input.h"

Array<bool>* Input::s_Keys = nullptr;

Input::Input(Array<bool>* keys)
{
	s_Keys = keys;
}

Input::~Input()
{
	s_Keys = nullptr;
}

bool Input::IsKeyDown(unsigned int key)
{
	return s_Keys->operator[](key);
}

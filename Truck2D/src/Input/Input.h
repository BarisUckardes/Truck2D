#pragma once
#include <Input/Keys.h>
#include <Core/Core.h>
#include <Memory/Array.h>

/// <summary>
/// A input receiver class.
/// Used to catch inputs for component objects
/// </summary>
class EXPORT Input
{
	friend class Window;
public:
	Input(Array<bool>* keys);
	~Input();

	/// <summary>
	/// Returns whether the specified key is down or not
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	FORCEINLINE static bool IsKeyDown(unsigned int key);
private:

	/// <summary>
	/// An internal key state setter only to be called from a Window class
	/// </summary>
	/// <param name="key"></param>
	/// <param name="state"></param>
	void SetKeyStateInternal(unsigned int key, bool state);

	static Array<bool>* s_Keys;
};


#pragma once
#include <Core/Core.h>


/// <summary>
/// Simple gui painter interface to be implemented by custom gui painters
/// </summary>
class IGUIPainter
{
public:
	IGUIPainter() = default;
	~IGUIPainter() = default;

	/// <summary>
	/// Caled when gui painter first created
	/// </summary>
	virtual void OnGUIEnable() = 0;

	/// <summary>
	/// Called every frame
	/// </summary>
	virtual void OnGUIPaint() = 0;

	/// <summary>
	/// Its a dummy function, not likely to be used
	/// </summary>
	virtual void OnGUIFinalize() = 0;
};


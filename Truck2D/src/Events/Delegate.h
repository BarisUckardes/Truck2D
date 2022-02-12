#pragma once
#include <Core/Event.h>
#include <functional>

template<typename TReturn, typename...TParameters>
/// <summary>
/// Simple delegate implementation similiar to C# delegates
/// </summary>
/// <typeparam name="...TParameters"></typeparam>
/// <typeparam name="TReturn"></typeparam>
class Delegate
{
public:
	Delegate(std::function<TReturn(TParameters...)> function)
	{
		m_FunctionPtr = function;
	}
	Delegate() = default;

	~Delegate()
	{

	}

	/// <summary>
	/// Returns the address of the target function pointer
	/// </summary>
	/// <returns></returns>
	FORCEINLINE size_t GetAddress() const
	{
		typedef TReturn(fnType)(TParameters...);
		fnType** fnPointer = GetFunctionPtr().template target<fnType*>();
		return (size_t)*fnPointer;
	}

	/// <summary>
	/// Invokes the delegate
	/// </summary>
	/// <param name="...parameters"></param>
	void Invoke(TParameters... parameters)
	{
		m_FunctionPtr(parameters...);
	}
private:
	/// <summary>
	/// Returns the function pointer
	/// </summary>
	/// <returns></returns>
	FORCEINLINE std::function<TReturn(TParameters...)> GetFunctionPtr() const
	{
		return m_FunctionPtr;
	}
	std::function<TReturn(TParameters...)> m_FunctionPtr;
};

template<typename TReturn, typename...TParameters>
static bool operator ==(const Delegate<TReturn, TParameters...>& a, const Delegate<TReturn, TParameters...>& b)
{
	return a.GetAddress() == b.GetAddress();
}
template<typename TReturn, typename...TParameters>
static bool operator !=(const Delegate<TReturn, TParameters...>& a, const Delegate<TReturn, TParameters...>& b)
{
	return a.GetAddress() != b.GetAddress();
}
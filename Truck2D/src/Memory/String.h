#pragma once
#include <Core/Core.h>


/// <summary>
/// Basic string implementation
/// </summary>
class EXPORT String
{
public:
	/// <summary>
	/// Returns a string representation of the float variable
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	static String GetFromFloat(float value);

	/// <summary>
	/// Returns an string represetntation of the integer variable
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	static String GetFromInteger(int value);

	/// <summary>
	/// Returns a float from the string
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	static float ToFloat(const String& value);

	/// <summary>
	/// Returns an integer from the string
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	static int ToInteger(const String& value);

	String();
	String(const String& other);
	String(const char* other);
	String(unsigned int size);
	String(const char* target, unsigned int size);

	~String();

	/// <summary>
	/// Returns the current char amount in this string
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetCursor() const;

	/// <summary>
	/// Returns a pointer to the source data
	/// </summary>
	/// <returns></returns>
	char* GetSource() const;


	/// <summary>
	/// Clears the memory of the string
	/// </summary>
	void Clear();

	/*
	* Operators
	*/
	const char* operator*() const;
	void operator+=(const String& other);
	void operator+=(const char* other);
	void operator+=(char other);
	char operator[](unsigned int index) const;
	void operator=(const String& other);

private:
	char* m_Source;
	unsigned int m_Cursor;
};

EXPORT String operator+(const String& target0, const String& target1);
EXPORT bool operator==(const String& target0, const String& target1);
EXPORT bool operator!=(const String& target0, const String& target1);


#pragma once
#include <iostream>

class String
{
private:
	char* value;
	void copy(const String& other);
	void erase();

public:
	String();
	String(const  char* value);
	String(const String& other);
	String& operator=(const String& other);
	bool operator==(const String& other);
	void print() const;
	~String();
};


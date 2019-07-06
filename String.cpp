#include "stdafx.h"
#include"String.h"

void String::copy(const String& other)
{
	this->value = new char[strlen(other.value) + 1];
	strcpy_s(this->value, strlen(this->value), other.value);
}
void String::erase()
{
	delete[] value;
}
String::String()
{
	this->value = new char[1];
	strcpy_s(this->value, strlen(this->value), "");
}

String ::~String()
{
	this->erase();
}

String::String(const String&other)
{
	this->copy(other);
}

String::String(const char* value)
{
	this->value = new char[strlen(value) + 1];
	strcpy_s(this->value, strlen(this->value), value);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

bool String:: operator==(const String& other)                   // Сравнява два стринга
{
	if (this != &other)
	{
		if (strlen(this->value) != strlen(other.value))
		{
			return false;
		}
		else
		{
			for (int i = 0; i < strlen(this->value); i++)
			{
				if (this->value[i] != other.value[i])
				{
					return 0;
				}
			}
			return 1;
		}
		
	}
	return false;
	
}

void String::print() const
{
	std::cout << this->value << std::endl;
}

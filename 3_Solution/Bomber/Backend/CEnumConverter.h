#pragma once
#include <string>

//	Template
template<typename EnumType>
class CEnumConverter
{
public:
	static std::string StringifyType(EnumType _type);
	static EnumType UnstringifyType(std::string _type);
};

template<typename EnumType>
std::string CEnumConverter<EnumType>::StringifyType(EnumType _type)
{
	return std::to_string(static_cast<unsigned int>(_type));;
}

template<typename EnumType>
EnumType CEnumConverter<EnumType>::UnstringifyType(std::string _type)
{
	return static_cast<EnumType>(std::stoi(_type));
}
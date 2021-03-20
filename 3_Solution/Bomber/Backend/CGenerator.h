#pragma once
class CGenerator
{
private:
	unsigned int m_currentID;
public:
	CGenerator() :m_currentID(0) {};
	CGenerator(unsigned int _value) :m_currentID(_value) {};
	unsigned int GetNextID();
	bool CheckIfValid(unsigned int _value) const;
	void SetValue(unsigned int _value);
};


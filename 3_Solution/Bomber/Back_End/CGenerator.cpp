#include "CGenerator.h"

unsigned int CGenerator::GetNextID()
{
	unsigned int returned;

	returned = (this->m_currentID)++;
	return returned;
}

bool CGenerator::CheckIfValid(unsigned int _value) const
{
	if (_value < this->m_currentID)
		return true;
	return false;
}

void CGenerator::SetValue(unsigned int _value)
{
	this->m_currentID = _value;
}
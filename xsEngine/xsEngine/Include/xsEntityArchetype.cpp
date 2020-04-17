#include "xsEntityArchetype.h"

bool xs::EntityArchetype::Equal(const xs::EntityArchetype& e1)
{
	return mIndex == e1.mIndex;
}

bool xs::EntityArchetype::Inequality(const xs::EntityArchetype& e1)
{
	return mIndex != e1.mIndex;
}

bool operator== (const xs::EntityArchetype& ae1, const xs::EntityArchetype& ae2)
{
	return ae1.mIndex == ae2.mIndex;
}

bool operator!= (const xs::EntityArchetype& ae1, const xs::EntityArchetype& ae2)
{
	return ae1.mIndex != ae2.mIndex;
}
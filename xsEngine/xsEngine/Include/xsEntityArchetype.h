#pragma once
#include "xsUtilities.h"

namespace xs
{
	struct EntityArchetype
	{
		bool Equal(const EntityArchetype& e1);
		bool Inequality(const EntityArchetype& e1);

		u32 mIndex, mComponentCount;
	};
}

bool operator== (const xs::EntityArchetype& ae1, const xs::EntityArchetype& ae2);
bool operator!= (const xs::EntityArchetype& ae1, const xs::EntityArchetype& ae2);
#pragma once
#include "xsUtilities.h"

namespace xs
{
	struct Entity
	{
		Entity() = default;
		Entity(const Entity&) = default;
		Entity(Entity&&) = default;
		Entity(u32 index, u32 version)
			:mIndex{ index }, mVersion{ version }
		{
		}

		Entity& operator= (const Entity&) = default;
		Entity& operator= (Entity&&) = default;


		u32 mIndex, mVersion;

		friend bool operator== (const Entity&, const Entity&);
		friend bool operator!= (const Entity&, const Entity&);

		static Entity Null;
	};
}
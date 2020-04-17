#pragma once
#include "xsEntity.h"

namespace xs
{
	struct EntityData
	{
		EntityData() = default;
		EntityData(u32 next)
			:mNext{next}, mEntVersion {0}, mComponentCount{0}, mArchetypeIndex{-1}, mIsDead{true}
		{}

		EntityData(const EntityData&) = default;
		EntityData(EntityData&&) = default;

		EntityData& operator= (const EntityData&) = default;
		EntityData& operator= (EntityData&&) = default;

		u32  mEntVersion, mComponentCount, mNext;
		s32  mArchetypeIndex;
		bool mIsDead;
	};
}
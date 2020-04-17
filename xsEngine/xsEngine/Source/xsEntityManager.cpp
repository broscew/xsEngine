#include "../Include/xsEntityManager.h"

namespace xs
{
	void EntityManager::OnBeforeDestroy()
	{
	}

	void EntityManager::OnAfterDestroy()
	{
	}

	void EntityManager::OnBeforeCreate(shared_ptr<World> world, uint32_t capacity)
	{
		mWorld = world;
		mCapacity = capacity;
		mEntityDatas.reserve(capacity);
		mIsCreated = true;
	}

	s32 EntityManager::GetEntityCapactity()
	{
		return mCapacity;
	}

	bool EntityManager::IsCreated()
	{
		return mIsCreated;
	}


	EntityArray EntityManager::GetAliveEntities()
	{
		EntityArray tmp;
		for (uint32_t i = 0; i < mEntityDatas.size(); ++i)
			if (!mEntityDatas[i].mIsDead)
				tmp.emplace_back(i + 1, mEntityDatas[i].mEntVersion);
		return tmp;
	}

	s32 EntityManager::GetComponentCount(Entity)
	{
		return 0;
	}

	s32 EntityManager::GetArchetypeIndex(Entity)
	{
		return 0;
	}
}
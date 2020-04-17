#include "../Include/xsComponentSystem.h"

namespace xs
{
	void ComponentSystem::OnBeforeDestroy()
	{
	}

	void ComponentSystem::OnBeforeCreate(shared_ptr<World> world, u32 capacity)
	{
		mWorld = world;
		mCapacity = capacity;
	}
}
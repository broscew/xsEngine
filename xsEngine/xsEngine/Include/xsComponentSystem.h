#pragma once
#include "xsComponentSystemBase.h"

namespace xs
{
	class ComponentSystem : public ComponentSystemBase
	{
	public:
	protected:
		virtual void OnBeforeDestroy() final override;
		virtual void OnBeforeCreate(shared_ptr<World> world, u32 capacity) final override;
		virtual void OnUpdate() = 0;
	private:
	};
}
#pragma once
#include "xsUtilities.h"

namespace xs
{
	class World;

	class SciptBehaviourManager
	{
		friend World;

	public:
		virtual void Update() {}
		virtual ~SciptBehaviourManager() {}
	protected:
		virtual void OnBeforeDestroy() = 0;
		virtual void OnAfterDestroy() = 0;
		virtual void OnBeforeCreate(shared_ptr<World> world, u32 capacity) = 0;
		virtual void OnCreate(u32) {};
		virtual void OnDestory() {};
	private:
	};
}
#pragma once
#include "xsScriptBehaviourManager.h"

namespace xs
{
	struct ComponentGroup;
	class World;
	class EntityManager;

	class ComponentSystemBase : public SciptBehaviourManager
	{
		enum class SystemType
		{
			Initialise = 0,
			Simulation,
			Presentation
		};

		friend World;
	public:
		ComponentSystemBase()
			:mType{SystemType::Simulation}, mCapacity{0}, mSysPriority{0}, mIsEnabled{true}
		{}


		virtual void Update() final;

		u32 GetSystemPriority() const;
		void SetSystemType(SystemType type);

		void Enable();
		void Disable();
		bool IsEnabled();

	protected:
		virtual void OnBeforeDestroy() override = 0;
		virtual void OnAfterDestroy() override {};
		virtual void OnBeforeCreate(shared_ptr<World> world, u32 capacity) override = 0;

		//Used to handle stuff the system needs before it starts running
		virtual void OnStartRunning() {};
		//Used to handle stuff the system needs to settle before it stops running
		virtual void OnStopRunning() {};

		virtual void OnUpdate() = 0;
		void PreUpdateInjectedComponenetGroups();
		void PosUpdateInjectedComponentGroups();

		shared_ptr<World> mWorld;
		shared_ptr<EntityManager> mEntityManager;
		
		u32 mCapacity;
		u32 mSysPriority;

		SystemType mType;
	private:
		u8 mIsEnabled;
	};
}

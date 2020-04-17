#pragma once

#include "xsUtilities.h"
#include "xsCString.h"
#include"xsComponent.h"
#include "xsTypeId.h"

namespace xs
{
	class comp_info;

	//This object handles the different component type's information and generation
	class TypeManager
	{
	public:
		enum class TypeCategory : u32
		{
			ComponentData = 0,
			SharedComponentData
		};

		enum class ComType
		{
			System = 0,
			Game
		};

		struct ComponentRegistry
		{
			ComponentRegistry() = default;
			ComponentRegistry(xsDS::hash64 hash, u32 size, TypeManager::TypeCategory category, TypeManager::ComType ct)
				:mHash{ hash }, mSize{ size }, mCategory{ category }, mComType{ ct }
			{}
			ComponentRegistry(const ComponentRegistry&) = default;
			ComponentRegistry(ComponentRegistry&&) = default;
			
			ComponentRegistry& operator= (const ComponentRegistry&) = default;
			ComponentRegistry& operator= (ComponentRegistry&&) = default;

			TypeManager::TypeCategory mCategory;
			TypeManager::ComType mComType;
			u32 mSize;
			xsDS::hash64 mHash;
		};

		template<typename ComponentType>
		struct RegisterGameComponent
		{
			RegisterGameComponent(const std::string& names)
			{
				const xsDS::CString toHash{ names.c_str() };
				const xsDS::hash64 hash = toHash.hash();
				mRegistry[hash] = ComponentRegistry{ hash, sizeof(ComponentType),
					TypeManager::TypeCategory::ComponentData, TypeManager::ComType::Game };

				mComponentData[hash] = make_shared<ComponentType>();
			}
		};

		template<typename ComponentType>
		struct RegisterSystemComponent
		{
			RegisterSystemComponent(const std::string& names)
			{
				const xsDS::CString toHash{ names.c_str() };
				const xsDS::hash64 hash = toHash.hash();
				mRegistry[hash] = ComponentRegistry{ hash, sizeof(ComponentType),
					TypeManager::TypeCategory::ComponentData, TypeManager::ComType::System };

				mComponentData[hash] = make_shared<ComponentType>();
			}
		};

		static ComponentRegistry GetComponentRegistry(xsDS::hash64 hash)
		{
			auto result = mRegistry[hash];
			return result;
		}
		
		static ComponentRegistry GetComponentRegistry(const comp_info& info) 
		{
			auto result = mRegistry[info.GetHash()];
			return result;
		}

		static bool IsTypeGame(xsDS::hash64 hash)
		{
			return mRegistry[hash].mComType == ComType::Game;
		}

		static bool IsTypeGame(const comp_info& info)
		{
			return mRegistry[info.GetHash()].mComType == ComType::Game;
		}

		static bool IsTypeSystem(xsDS::hash64 hash)
		{
			return mRegistry[hash].mComType == ComType::System;
		}
		
		static bool IsTypeSystem(const comp_info& info)
		{
			return mRegistry[info.GetHash()].mComType == ComType::System;
		}

		static u32 GetComponentSize(xsDS::hash64 hash)
		{
			return mRegistry[hash].mSize;
		}

		static u32 GetComponentSize(const comp_info& info)
		{
			return mRegistry[info.GetHash()].mSize;
		}

		static shared_ptr<IComponentData> CreateComponent(xsDS::hash64 hash)
		{
			return mComponentData[hash];
		}

		static shared_ptr<IComponentData> CreateComponent(const comp_info& hash)
		{
			return mComponentData[hash.GetHash()];
		}
	protected:
	private:
		TypeManager() = delete;

		static std::unordered_map<u64, ComponentRegistry> mRegistry;
		static std::unordered_map<u64, shared_ptr<IComponentData>> mComponentData;
	};

	std::unordered_map<u64, TypeManager::ComponentRegistry> TypeManager::mRegistry;
	std::unordered_map<u64, shared_ptr<IComponentData>> TypeManager::mComponentData;



#define REGISTER_GAME_COMPONENT(type)\
namespace xs{\
namespace Components{\
namespace Registry{\
	xs::TypeManager::RegisterGameComponent<type> Registry_##type { #type };\
}}}

#define REGISTER_SYSTEM_COMPONENT(type)\
namespace xs{\
namespace Components{\
namespace Registry{\
	xs::TypeManager::RegisterGameComponent<type> Registry_##type { #type };\
}}}
}



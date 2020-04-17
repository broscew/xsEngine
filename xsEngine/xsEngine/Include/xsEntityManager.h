#pragma once
#include "xsUtilities.h"
#include "xsScriptBehaviourManager.h"
#include "xsEntityData.h"
#include "xsComponentType.h"
#include "xsEntityArchetype.h"


namespace xs
{
	using EntityArray = std::vector<xs::Entity>;
	using EntityDataArray = std::vector<xs::EntityData>;
	class World;

	class EntityManager : public SciptBehaviourManager
	{
		friend World;
	public:

		//System related functions
		s32   GetEntityCapactity();//get the amount of entity the manager supports
		bool  IsCreated();//Use only for LE::World

		//Archetype management
		template <typename ... Components>
		EntityArchetype GetorCreateArchetype()
		{
			//EntityArchetype ea{};
			//std::set<xsDS::hash64> sig;
			////use fold expression to expand
			//((sig.insert(compid<Components>().GetHash(), ...);

			//auto ae_itr = std::find(_archetypeSignature.begin(), _archetypeSignature.end(), sig);

			//if (ae_itr == _archetypeSignature.end())
			//{
			//	_archetypeSignature.emplace_back(std::move(sig));
			//	ea._archetypeIndex = static_cast<uint32_t>(_archetypeSignature.size() - 1);
			//	ea._componentCount = static_cast<uint32_t>(sizeof...(Components));
			//	_archetypalEntityArray.emplace_back();
			//}
			//else
			//{
			//	ea._archetypeIndex = static_cast<uint32_t>(ae_itr - _archetypeSignature.begin());
			//	ea._componentCount = static_cast<uint32_t>(sizeof...(Components));
			//}


			//return ea;
		}

		EntityArchetype GetorCreateArchetype(const std::vector<ComponentType>& arr);

		//Entity Managment

		//Handles the creation of the entity
		/*template <typename ... Components>
		Entity CreateEntity(Components&& ... values)
		{
			Entity result{};

			auto arch = GetorCreateArchetype<Components...>();

			if (_freeIndices.size() > MAX_ENT_BEFORE_REUSE)
			{
				result._index = _freeIndices.front();
				result._version = _entityDataArray[result._index - 1]._entVersion;
				_freeIndices.pop_front();
				_entityDataArray[result._index - 1]._componentCount = static_cast<uint32_t>(sizeof...(Components));
				_entityDataArray[result._index - 1]._archetypeIndex = arch._archetypeIndex;
				_entityDataArray[result._index - 1]._isDead = false;
			}
			else
			{
				result._index = static_cast<uint32_t>(_entityDataArray.size() + 1);
				result._version = 0;
				EntityData ed{};
				ed._entVersion = 0;
				ed._archetypeIndex = arch._archetypeIndex;
				ed._componentCount = static_cast<uint32_t>(sizeof...(Components));
				_entityDataArray.emplace_back(std::move(ed));
			}
			_archetypalEntityArray[arch._archetypeIndex].push_back(result);

			if constexpr ((sizeof...(Components) > 0))
			{
				_chunkMgr->AddEntriesToChunk(result, std::move(values)...);
				std::vector<std::type_index> types;
				(types.push_back(typeid(Components)), ...);

				for (auto type : types)
				{
					_evtmgr->publish(New<LE::EVENT::ComponentCreateEvent>(result, type));
				}
			}

			_evtmgr->publish(New<LE::EVENT::EntityCreateEvent>(result));

			return result;
		}*/

		//Creates an entity using an archetype
		Entity       CreateEntity(EntityArchetype archetype);

		//Destroy a given entity
		void         DestroyEntity(Entity);

		//Check if the entity is still valid 
		bool         Exist(Entity);

		//Get All entities that are alived
		EntityArray  GetAliveEntities();
		s32          GetComponentCount(Entity);
		s32          GetArchetypeIndex(Entity);

		//Creates a identical Entity
		Entity  Instantiate(Entity src);

		//Template functions

		//Adds component to the entity, if the same component is added behaviour is undefined
		//template <typename ComponentData>
		//void AddComponentData(Entity entity, ComponentData&& data)
		//{
		//	if (!Exist(entity))
		//		return;

		//	_chunkMgr->AddEntryToChunk(std::move(entity), std::move(data));
		//	//update entity entry
		//	EntityData& ed = _entityDataArray[entity._index - 1];
		//	++ed._componentCount;

		//	_archetypalEntityArray[ed._archetypeIndex].erase(std::remove(_archetypalEntityArray[ed._archetypeIndex].begin(), _archetypalEntityArray[ed._archetypeIndex].end(), entity), _archetypalEntityArray[ed._archetypeIndex].end());

		//	auto sig = _archetypeSignature[ed._archetypeIndex];
		//	sig.insert(TypeManager::Instance().GetTypeIndex<ComponentData>());
		//	auto ae_itr = std::find(_archetypeSignature.begin(), _archetypeSignature.end(), sig);
		//	if (ae_itr != _archetypeSignature.end())
		//	{
		//		ed._archetypeIndex = static_cast<uint32_t>(ae_itr - _archetypeSignature.begin());
		//		_archetypalEntityArray[ed._archetypeIndex].emplace_back(entity);

		//	}
		//	else
		//	{
		//		_archetypeSignature.emplace_back(std::move(sig));
		//		ed._archetypeIndex = static_cast<uint32_t>(_archetypeSignature.size() - 1);
		//		_archetypalEntityArray.emplace_back();
		//		_archetypalEntityArray[ed._archetypeIndex].emplace_back(entity);
		//	}

		//	_evtmgr->publish(New<LE::EVENT::ComponentCreateEvent>(entity, typeid(ComponentData)));
		//}

		////Set component for the Entity
		//template <typename ComponentData>
		//void SetComponentData(Entity entity, ComponentData&& data)
		//{
		//	EntityData& ed = _entityDataArray[entity._index - 1];
		//	auto sig = _archetypeSignature[ed._archetypeIndex];
		//	auto itr = sig.find(TypeManager::Instance().GetTypeIndex<ComponentData>());

		//	if (itr != sig.end())
		//	{
		//		_chunkMgr->SetEntryToChunk(entity, std::move(data));
		//	}
		//}

		////Get Component Data from entity
		//template <typename ComponentData>
		//ComponentData GetComponentData(Entity entity)
		//{
		//	if (Exist(entity))
		//	{
		//		EntityData& ed = _entityDataArray[entity._index - 1];
		//		auto sig = _archetypeSignature[ed._archetypeIndex];
		//		auto itr = sig.find(TypeManager::Instance().GetTypeIndex<ComponentData>());

		//		if (itr != sig.end())
		//		{

		//			return _chunkMgr->GetEntryToChunk<ComponentData>(entity);
		//		}
		//		else
		//		{
		//			return ComponentData{ };
		//		}


		//	}

		//	return ComponentData{ };
		//}

		////Remove component data from entity
		//template <typename ComponentData>
		//void RemoveComponentData(Entity entity)
		//{
		//	if (!Exist(entity))
		//		return;

		//	//Get the entity's archetype 
		//	_evtmgr->publish(New<LE::EVENT::ComponentRemoveEvent>(entity, typeid(ComponentData)));

		//	EntityData& ed = _entityDataArray[entity._index - 1];
		//	auto sig = _archetypeSignature[ed._archetypeIndex];
		//	auto itr = sig.find(TypeManager::Instance().GetTypeIndex<ComponentData>());

		//	//Remove the data of the entity
		//	if (itr != sig.end())
		//	{
		//		sig.erase(itr);

		//		_chunkMgr->RemoveEntryToChunk<ComponentData>(entity);

		//		--ed._componentCount;

		//		_archetypalEntityArray[ed._archetypeIndex].erase(std::remove(_archetypalEntityArray[ed._archetypeIndex].begin(), _archetypalEntityArray[ed._archetypeIndex].end(), entity), _archetypalEntityArray[ed._archetypeIndex].end());


		//		auto ae_itr = std::find(_archetypeSignature.begin(), _archetypeSignature.end(), sig);
		//		if (ae_itr != _archetypeSignature.end())
		//		{
		//			ed._archetypeIndex = static_cast<uint32_t>(ae_itr - _archetypeSignature.begin());
		//			_archetypalEntityArray[ed._archetypeIndex].emplace_back(entity);

		//		}
		//		else
		//		{
		//			_archetypeSignature.emplace_back(std::move(sig));
		//			ed._archetypeIndex = static_cast<uint32_t>(_archetypeSignature.size() - 1);

		//			if (ed._archetypeIndex < _archetypalEntityArray.size())
		//				_archetypalEntityArray[_archetypeSignature.size() - 1].emplace_back(entity);
		//			else
		//			{
		//				_archetypalEntityArray.emplace_back();
		//				_archetypalEntityArray[_archetypeSignature.size() - 1].emplace_back(entity);
		//			}
		//		}
		//	}
		//}

		////Check if entity has a specific component
		//template <typename ComponentData>
		//bool HasComponents(Entity entity)
		//{
		//	if (Exist(entity))
		//	{
		//		EntityData& ed = _entityDataArray[entity._index - 1];

		//		if (ed._archetypeIndex < 0)
		//			return false;

		//		auto sig = _archetypeSignature[ed._archetypeIndex];
		//		auto itr = sig.find(TypeManager::Instance().GetTypeIndex<ComponentData>());

		//		return (itr != sig.end());
		//	}
		//	else
		//	{
		//		return false;
		//	}

		//}

	protected:
		virtual void OnBeforeDestroy() override;
		virtual void OnAfterDestroy() override;
		virtual void OnBeforeCreate(shared_ptr<World> world, uint32_t capacity) override;
	private:
		EntityDataArray                mEntityDatas;          //stores all entity data
		std::deque <u32>               mFreeIndices;          //index appearing here shows that the Entity is Dead
		std::vector<EntityDataArray>   mArchetypalEntityArray;//use to store entities following a particular archetypal type
		std::vector<std::set<int32_t>> mArchetypeSignatures;  //archetypal signature

		shared_ptr<World> mWorld;
		u32 mfreelist;
		u32 mCapacity;
		bool mIsCreated;
	};
}

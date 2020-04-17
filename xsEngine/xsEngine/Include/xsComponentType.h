#pragma once
#include "xsUtilities.h"
#include "xsTypeManager.h"

namespace xs
{
	//This is used by component groups to query for information
	//and retrieve behaviours
	struct ComponentType
	{
		//This is the list of available behaviours that the user can query
		enum class AccessMode
		{
			ReadOnly = 0,
			ReadWrite,
			Subtractive
		};


		ComponentType(ComponentType::AccessMode mode = AccessMode::ReadWrite)
			:mMode{mode},mHash{0}
		{}

		ComponentType(const comp_info& info, ComponentType::AccessMode mode = AccessMode::ReadWrite)
			:mMode{ mode }, mHash{ info.GetHash() }
		{}

		template<typename T>
		static ComponentType ReadWrite()
		{
			
			return { xs::compid<T>(), AccessMode::ReadWrite };
		}

		template<typename T>
		static ComponentType ReadyOnly()
		{

			return { xs::compid<T>(), AccessMode::ReadOnly };
		}

		template<typename T>
		static ComponentType Subtractive()
		{

			return { xs::compid<T>(), AccessMode::Subtractive };
		}

		//Non templatize version of the same thing
		static ComponentType ReadWrite(const comp_info& info)
		{
			return { info, AccessMode::ReadWrite };
		}

		static ComponentType ReadOnly(const comp_info& info)
		{
			return { info, AccessMode::ReadOnly };
		}
		
		static ComponentType Subtractive(const comp_info& info)
		{
			return { info, AccessMode::Subtractive };
		}

		


		//Operator Overloading
		friend bool operator== (ComponentType lhs, ComponentType rhs)
		{
			return lhs.mHash == rhs.mHash;
		}

		friend bool operator!= (ComponentType lhs, ComponentType rhs)
		{
			return lhs.mHash != rhs.mHash;
		}

		friend bool operator>  (ComponentType lhs, ComponentType rhs)
		{
			return lhs.mHash > rhs.mHash;
		}
		
		friend bool operator<  (ComponentType lhs, ComponentType rhs)
		{
			return lhs.mHash < rhs.mHash;
		}

		ComponentType::AccessMode mMode;
		xsDS::hash64 mHash;
	};
}
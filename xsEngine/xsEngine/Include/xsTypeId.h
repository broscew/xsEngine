#pragma once
#include "xsHash.h"
#include "xsCString.h"
#include "xsUtilities.h"
#include "xsNameof.h"

namespace xs
{
	class comp_info
	{
	public:
		constexpr comp_info(const char* name)
			:mName{ name },  mHash {mName.hash()}
		{}

		constexpr comp_info(const xsDS::CString& name)
			: mName{ name }, mHash{ name.hash() }
		{}

		comp_info(const comp_info&) = default;
		comp_info(comp_info&&) = default;

		comp_info& operator=(const comp_info&) = default;
		comp_info& operator=(comp_info&&) = default;

		constexpr xsDS::hash64 GetHash() const
		{
			return mHash;
		}

		friend constexpr bool operator== (const comp_info& lhs, const comp_info& rhs)
		{
			return lhs.mHash == rhs.mHash;
		}

		friend constexpr bool operator!= (const comp_info& lhs, const comp_info& rhs)
		{
			return lhs.mHash != rhs.mHash;
		}

	private:
		xsDS::CString mName;
		xsDS::hash64 mHash;
	};


	template<typename ComponentType>
	constexpr comp_info compid()
	{
		return { xsUtil::nameof<ComponentType>() };
	}
}
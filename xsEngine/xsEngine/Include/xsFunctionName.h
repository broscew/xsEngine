#pragma once
#include "xsCString.h"

#define XS_FUNCTIONNAME_PREFIX "class xsDS::CString __cdecl xsUtil::type<"
#define XS_FUNCTIONNAME_SUFFIX ">(void)"

#define XS_FUNCTIONNAME_LEFT (sizeof(XS_FUNCTIONNAME_PREFIX) - 1)
#define XS_FUNCTIONNAME_RIGTH (sizeof(XS_FUNCTIONNAME_SUFFIX) - 1)

namespace xsUtil
{
	template<typename T>
	constexpr xsDS::CString type()
	{
		return { __FUNCSIG__ };
	}
}
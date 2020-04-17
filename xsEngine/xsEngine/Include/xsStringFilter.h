#pragma once
#include "xsCString.h"

namespace xsUtil
{
	constexpr xsDS::CString filter_prefix(const xsDS::CString& str, const xsDS::CString& prefix)
	{
		return str.size() >= prefix.size() ? (str(0, prefix.size()) == prefix ? str(prefix.size(), str.size()) : str) : str;
	}

	constexpr xsDS::CString leftpad(const xsDS::CString& str)
	{
		return (str.size() && str[0] == ' ') ? leftpad(str(1, str.size())) : str;
	}

	constexpr xsDS::CString filter_struct(const xsDS::CString& str)
	{
		return leftpad(filter_prefix(leftpad(str), "struct"));
	}

	constexpr xsDS::CString filter_class(const xsDS::CString& str)
	{
		return leftpad(filter_prefix(leftpad(str), "class"));
	}

	constexpr xsDS::CString filter_typename_prefix(const xsDS::CString& str)
	{
		return filter_struct(filter_class(str));
	}
}
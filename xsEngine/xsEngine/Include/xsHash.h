#pragma once

#include "xsUtilities.h"

namespace xsDS
{
	//Based on http://www.isthe.com/chongo/tech/comp/fnv/#FNV-1a
	typedef u64 hash64;
	constexpr hash64 offset_basis = 14695981039346656037ull;
	constexpr hash64 offset_prime = 1099511628211ull;

	constexpr hash64 hash_fnv1a(u64 n, const char* str, hash64 hash = offset_basis)
	{
		return n > 0 ? hash_fnv1a(n - 1, str + 1, (hash ^ *str) * offset_prime) : hash;
	}

	template <u64 N>
	constexpr hash64 hash_fnv1a(const char(&array)[N])
	{
		return hash_fnv1a(N-1, &array[0]);
	}
}
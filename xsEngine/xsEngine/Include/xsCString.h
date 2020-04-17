#pragma once

#include "xsUtilities.h"
#include "xsHash.h"
#include "xsCAlgorithm.h"
#include <string>
#include <ostream>

namespace xsDS
{
	//This is a compile time string class
	class CString
	{
	public:
		template <u64 N>
		constexpr CString(const char (&str) [N])
			: CString{str, N}
		{}

		constexpr CString(const char* begin, u64 length)
			:mData{begin}, mLength{length}
		{}

		constexpr CString(const char* begin, const char* end)
			:CString(begin, static_cast<u64>(end - begin))
		{}

		constexpr CString(const char* begin)
			:CString{begin, length(begin)}
		{
		}

		static constexpr u64 length(const char* str)
		{
			return *str ? 1 + length(str + 1) : 0;
		}

		constexpr u64 length() const
		{
			return mLength;
		}

		constexpr u64 size() const
		{
			return mLength;
		}

		constexpr hash64 hash() const
		{
			return hash_fnv1a(length(), begin());
		}

		std::string toStdString() const
		{
			return std::string{ mData, mData + mLength };
		}

		constexpr const char* begin() const
		{
			return mData;
		}

		constexpr const char* end() const
		{
			return mData + mLength;
		}

		constexpr char operator[](u64 index) const
		{
			return *(mData + index);
		}

		constexpr char operator()(u64 index) const
		{
			return *(mData + index);
		}

		constexpr CString operator()(u64 offset_start, u64 offset_end) const
		{
			return CString{ mData + offset_start, mData + offset_end };
		}

		constexpr CString pad(u64 offset_begin, u64 offset_end) const
		{
			return operator()(offset_begin, size() - offset_end);
		}

		friend std::ostream& operator<<(std::ostream& os, const CString& str)
		{
			for (auto c : str)
			{
				os << c;
			}

			return os;
		}

	protected:
	private:
		const char* mData;
		u64 mLength;
	};

	constexpr bool operator==(const CString& lhs, const CString& rhs)
	{
		return xsCAlgo::is_equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	constexpr bool operator!=(const CString& lhs, const CString& rhs)
	{
		return !(lhs == rhs);
	}
}
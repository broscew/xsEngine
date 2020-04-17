#pragma once
#include "xsUtilities.h"

namespace xsCAlgo
{
	template <typename lhsIter,typename rhsIter>
	constexpr bool is_equal(lhsIter lhsBegin, lhsIter lhsEnd, rhsIter rhsBegin, rhsIter rhsEnd)
	{
		return (lhsBegin != lhsEnd && rhsBegin != rhsEnd) ?
			(*lhsBegin == *rhsBegin) && (is_equal(lhsBegin + 1, lhsEnd, rhsBegin + 1, rhsEnd)) :
			(lhsBegin == lhsEnd && rhsBegin == rhsEnd);
	}

}

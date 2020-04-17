#include "../Include/xsEntity.h"

xs::Entity xs::Entity::Null{ 0,0 };

bool xs::operator==(const xs::Entity& lhs, const  xs::Entity& rhs)
{
	return (lhs.mIndex == rhs.mIndex) && (lhs.mVersion == rhs.mVersion);
}

bool xs::operator!=(const xs::Entity& lhs, const xs::Entity& rhs)
{
	return (lhs.mIndex != rhs.mIndex) || (lhs.mVersion != rhs.mVersion);
}

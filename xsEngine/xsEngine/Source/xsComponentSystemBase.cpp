#include"../Include/xsComponentSystemBase.h"


u32 xs::ComponentSystemBase::GetSystemPriority() const
{
	return mSysPriority;
}

void xs::ComponentSystemBase::SetSystemType(SystemType type)
{
	mType = type;
}

void xs::ComponentSystemBase::Enable()
{
	mIsEnabled = 1;
}

void xs::ComponentSystemBase::Disable()
{
	mIsEnabled = 0;
}

bool xs::ComponentSystemBase::IsEnabled()
{
	return mIsEnabled;
}

void xs::ComponentSystemBase::Update()
{
	PreUpdateInjectedComponenetGroups();
	OnUpdate();
	PosUpdateInjectedComponentGroups();
}
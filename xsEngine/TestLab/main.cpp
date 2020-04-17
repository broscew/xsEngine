#include <iostream>
#include "xsEngine.h"
#include "xsComponentType.h"
#include "xsFunctionName.h"
#include "TempHeader.h"
#include "xsNameof.h"
#include <memory>
#include <chrono>

struct TestObject
{

};

template<typename T>
struct WrapperTest
{
	
};

template<typename T>
struct Wrapper2Test
{

};

int main()
{
	xs::comp_info info = xs::compid<TestComponent1>();

	auto testcom1 = xs::TypeManager::GetComponentRegistry(info);

	auto ptr = xs::TypeManager::CreateComponent(info.GetHash());

	auto tptr = std::static_pointer_cast<TestComponent1>(ptr);

	TestComponent1 tc1{ *tptr };

	tc1.print();

	auto ct = xs::ComponentType::ReadOnly(info);

	return 0;
}
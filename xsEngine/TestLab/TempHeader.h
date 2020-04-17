#pragma once
#include "xsComponent.h"
#include "xsTypeManager.h"
#include <iostream>

struct TestComponent1 : xs::IComponentData
{
	void print()
	{
		std::cout << "Hi, this is TestComponent1!" << std::endl;
	}
};
REGISTER_GAME_COMPONENT(TestComponent1);

struct TestComponent2 : xs::IComponentData
{
	void print()
	{
		std::cout << "Hi, this is TestComponent2!" << std::endl;
	}
};
REGISTER_GAME_COMPONENT(TestComponent2);

//xs::TypeManager::RegisterComponent<TestComponent> object{ "TestComponent" };
// Fill out your copyright notice in the Description page of Project Settings.


#include "TEST/FSMTEST.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFsmTest,"Gameplay.Player.FSM", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FFsmTest::RunTest(const FString& Parameters)
{
	return false;
}
FSMTEST::FSMTEST()
{
}

FSMTEST::~FSMTEST()
{
}

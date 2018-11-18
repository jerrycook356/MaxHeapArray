/**@file PreCondViolatedExcep.cpp*/
#include "pch.h"
#include "PreCondViolatedExcep.h"

PreCondViolatedExcep::PreCondViolatedExcep(const string& message) :
	logic_error("Precondition value exception:" + message)
{

}//end constructor
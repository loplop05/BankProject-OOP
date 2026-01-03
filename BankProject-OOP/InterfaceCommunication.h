#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
using namespace std;

class InterfaceCommunication

{
public :
	virtual void SendEmaail(string title, string body) = 0;
	virtual void SendSMS(string title, string body) = 0;
	virtual void SendFax(string title, string body) = 0;

};
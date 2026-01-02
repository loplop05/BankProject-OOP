#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
using namespace std;


int main()
{
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}
	return 0;
}
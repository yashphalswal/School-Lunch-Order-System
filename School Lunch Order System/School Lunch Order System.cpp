#include <iostream>
#include <vector>
#include <Windows.h>
#include <vector>
#include "menu.h"
#include "login.h"
#include "registration.h"

using namespace std;


int main() {

    cout << "\t testing" << endl;

   
    parentRegistration();

    displayIntroductionScreen();
    IsLoggedIn();
    displayMainMenu();
    return 0;
}

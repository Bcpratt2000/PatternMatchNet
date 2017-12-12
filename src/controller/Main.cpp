/*
 * Main.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Ben Pratt
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include "../model/NetworkController.h"

using namespace std;

int main(){
	NetworkController network=NetworkController();
	string tempStr;
	while(tempStr!="exit" || tempStr!="quit"){
		cout << "Enter text: ";
		getline(cin, tempStr);
		cout << network.check(tempStr) << "\n" << endl;

	}
	return 0;
}


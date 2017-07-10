//
//  main.cpp
//  I2C-interface
//
//  Created by JS on 7/8/17.
//  Copyright © 2017 JS. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <sstream>
#include "bus/I2CDevice.h"

using namespace std;
using namespace exploringBB;

int main() {

        cout << "Starting I2C Example" << endl;
        I2CDevice *busDevice = new I2CDevice(1,0x0b);
        busDevice->write(39);


}

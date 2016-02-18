//
//  main.cpp
//  HW5
//
//  Created by Han Pham on 2/5/16.
//  Copyright © 2016 45C. All rights reserved.
//

#include "String.h"

void testString(){
    String firstString("First");
    String secondString("Second");
    String thirdString(firstString);
    String fourthString("Fourth");
    String fifthString = String();
    
    cout << "1. +: " << firstString + secondString << endl;
    cout << "2. +=: " << (firstString += secondString) << endl;
    cout << "3. indexOf(char): " << firstString.indexOf('t') << endl;
    cout << "4. LT: " << (secondString < firstString) << endl;
    cout << "5. <<: "<< fifthString << endl;
    cout << "6. <<: "<< fourthString << endl;
    cout << "7. ==: " << (fifthString == fourthString) << endl;
    cout << "8. []: "<< thirdString[1] << endl;
    fifthString = thirdString;
    cout << "9. <<: " << fifthString << " " << thirdString << endl;
    cout << "0. []: "<< fifthString[1] << endl;
    cout << "1. []: "<< fifthString[10] << endl;
    
    cout << "Enter a test string: ";
    cin  >> firstString;
    cout << firstString << endl;
    
    cout << (firstString < secondString) << endl;
    cout << (firstString == thirdString) << endl;
}

int main()
{
    testString();
    String::getAllocation();
}


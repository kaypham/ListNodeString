//
//  main.cpp
//  String
//
//  Created by Han Pham on 1/24/16.
//  Copyright © 2016 45C. All rights reserved.
//

#include "String.h"

char newLine[] = "\n\n";


void testConstructors(String firstString, String secondString, String emptyString, String secondEmptyString)
{
    cout << "TESTING CONSTRUCTORS" << endl;
    
    //Testing the 2 constructors (1) #CORRECT
    
    cout << "firstString is "  << firstString  << endl;
    cout << "secondString is " << secondString << endl;
    
    
    //Testing the 2 constructors taking the default empty string (2) #CORRECT
    
    cout << "emptyString is "      << emptyString       << endl;
    cout << "secondEmptyString is" << secondEmptyString << newLine;
}

void testOperatorAssign(String emptyString, String firstString, String secondEmptyString)
{
    //Testing operator =, assigning something to empty (1) #CORRECT
    cout << "TESTING OPERATOR =" << endl;
    emptyString = firstString;
    cout << "emptyString after the assignment " << emptyString << endl;
    cout << "firstString after the assignment " << firstString << endl;
    
    //Testing operator =, assigning its own value to itself, (2) #CORRECT
    //secondString = secondString;
    //cout << "secondString after the assignment " << secondString << endl;
    
    //Testing operator =, assigning empty to something, (3) #CORRECT
    emptyString = secondEmptyString;
    cout << "emptyString after the assignment " << emptyString << newLine;
}

void testOperatorIndex(String secondString, String secondEmptyString)
{
    //Testing opeartor [], should return h, (1) #CORRECT
    cout << "TESTING OPERATOR []" << endl;
    cout << "secondString at zero-based index 6 is " << secondString[6] << endl;
    
    //Testing operator [], taking an index of an empty string, (2) #CORRECT
    cout << "secondEmptyString at zero-based index 1 is " << secondEmptyString << newLine;
}

void testIndexOfC(String firstString, String emptyString)
{
    //Testing indexOf(c) of a non-empty string (1) #CORRECT
    cout << "TESTING INDEXOF(C)" << endl;
    cout << "Index of char h in firstString is " << firstString.indexOf('h') << endl;
    
    //Testing indexOf(c) of a non-empty string with a non-existant c (2) #orginally returned 0. Fixed by changing return NULL to return -1
    cout << "Index of char z in firstString is " << firstString.indexOf('z') << endl;
    
    //Testing indexOf(c) of an empty string (3) #same problem as above
    cout << "Index of char ' ' in emptyString is " << emptyString.indexOf(' ') << newLine;
}

void testEqual(String firstString, String testingEqualString, String emptyString)
{
    //Testing operator == (1) #compiler automatically print 1 if it is true. And include (..) for cout statement
    cout << "TESTING OPERATOR ==" << endl;
    cout << "Checking if tesetingEqualString is equal firstString " << (firstString == testingEqualString) << endl;
    
    //Testing operator == (2) #it automatically return 0, which indicates false. CORRECT
    cout << "Checking if empty is equal firstString " << (emptyString == firstString) << endl;
    
    //Testing opeartor ==, switching order of (2), (3) #CORRECT
    cout << "Checking if firstString is equal empty " << (firstString == emptyString) << newLine;
}

void testPlus(String firstString, String secondString, String emptyString)
{
    //Testing operator + (1)
    cout << "TESTING OPERATOR +" << endl;
    String answer;
    answer = firstString + secondString;
    cout << "Concatenation of 2 Doing homework's is " << answer << endl;
    cout << "The original string after the concatenation is " << firstString << endl;
    
    //Testing operator +, adding empty to firstString (2)
    answer = emptyString + firstString;
    cout << "Concatenation of emptyString and firstString is " << answer << endl;
    
    //Testing operator +, adding firstString to empty (3)
    answer = firstString + emptyString;
    cout << "Concatenation of firstString and emptyString is " << answer << newLine;
}

void testPlusEqual(String secondEmptyString)
{
    //Testing operator += (1)
    cout << "TESTING OPERATOR +=" << endl;
    char appendingArray[] = "X-code";
    char appendedArray[]  = " G++ ";
    String appendingString(appendingArray);
    String appendedString(appendedArray);
    cout << "Before appending, appendingString is " << appendingString << ", and appendedString is " << appendedString << endl;
    appendedString += appendingString;
    cout << "After appending appendingString to appendedString, appendingString is " << appendingString << ", and appendedString is " << appendedString << endl;
    
    //Testing operator +=, append emptyString to firstString (2)
    appendedString += secondEmptyString;
    cout << "After appending secondEmptyString to appendedString, appendedString is " << appendedString << ", and secondEmptyString is " << secondEmptyString << endl;
    
    //Testing operator +=, append firstString to emptyString (3)
    secondEmptyString += appendedString;
    cout << "After appending appendedString to secondEmptyString, secondEmptyString is " << secondEmptyString << ", and appendedString is " << appendedString << newLine;
}

void testCin()
{
    char inputString2[128];
    cout << "PLease enter a test string " << endl;
    cin  >> inputString2;
    cout << "What happends if I put in a long string? " << inputString2 << endl;
    String stringFromInput2(inputString2);
    cout << "Will it work after constructing it? " << inputString2 << newLine;
}

void test_string()
{
    char charArray[] = "Doing homework";
    
    String firstString(charArray);
    String secondString(firstString);
    
    String emptyString;
    String secondEmptyString;
    
    String testingEqualString = "Doing homework";
    cout << "TESTING BEGINS" << endl;
    testConstructors(firstString, secondString, emptyString, secondEmptyString);
    testOperatorAssign( emptyString,  firstString,  secondEmptyString);
    testOperatorIndex( secondString,  secondEmptyString);
    testIndexOfC( firstString,  emptyString);
    testEqual( firstString,  testingEqualString,  emptyString);
    testPlus( firstString,  secondString,  emptyString);
    testPlusEqual( secondEmptyString);
    testCin();
}

int main()
{
    test_string();
    String::getAllocation();
    cout << "THANK YOU!" << endl;
}

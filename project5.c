#include <stdio.h>
#include "project5.h"  // SUBMIT THS CODE
#pragma warning(disable:4996)
/* Usage: program username, date, etc....
Bellevue College CS212 Program Assignment #5
W.P. Iverson, instructor
May 2022
*/
/*
* Edited by: Tristan Lea
* Date: 5/5/22
*/
int main()
{
    char targetText[10] = "null"; // not initialized, creates problems?
    char orgName[100] = "United Nations";
    char userText[20] = "UNICEF";
    // Compiler might show warnings, but code does pass compiler
    printf("%s   %s   %s \n", "orgName      ", "userText", "targetText");
    printf("%s -  %s -  %s -\n", orgName, userText, targetText);
    strcpy(targetText, userText); // Copies "UNICEF" + null char to targetText 
    printf("strcpy: %s\n", targetText);
    /**/
    // Below will compile OK, causes run time errors
    //strcpy(targetText, orgName); // Copies "United Nations" first 10 char?? FIX
    //printf("targetText: %s\n", orgName);
    strncpy(orgName, userText, 6); // orgName is "UNICEF Nations"
    printf("strncpy: %s\n", orgName);
    strcat(orgName, userText); // orgName is "United NationsUNICEF"
    printf("strcat: %s\n", orgName);
    // Below will compile OK, causes run time errors
    //strcat(userText, orgName); // Not working when first parameter is too short??
    //FIX
        //printf("strcat: %s\n", userText);
        // Might be easier to follow with literal strings:
        strcpy(targetText, "abc");           // targetText is "abc"
    strncat(targetText, "123456789", 3); // targetText is "abc123"
    /**/
}
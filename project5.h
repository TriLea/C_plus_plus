/*
CS212 C-String Assignment
W.P. Iverson, instructor
April 2022
Write:
strcpy // lame start provided for prototype form
strncpy
strcat
*/
/*
* Edited by: Tristan Lea
* Date: 5/5/22
* project5.h header file
*/
#include <stdio.h>
#pragma once

char* strcpy(char* destStr, const char* srcStr)
{
    char* strRet = destStr;

    while ( *srcStr != '\0')
    {   
        *destStr++ = *srcStr++;
    }

    *deststr = '\0';

    return strRet;
}

char* strncpy(char* destStr, const char* srcStr, size_t count)
{
    char* strRet = destStr;

    while (count > 0)
    {
        if (*srcStr == '\0')
        {
            *destStr++ = *srcStr;
        }
        else
        {
            *destStr++ = *srcStr++;
        }
        count--;
    }
    return strRet;
}

char* strcat(char* destStr, const char* srcStr)
{   
    char* strRet = destStr;

    while (*destStr != '\0')
    {
        destStr++;
    }

    strcpy(destStr, srcStr);

    return strRet;
}

char* strncat(char* destStr, const char* srcStr, size_t count)
{
    char* strRet = destStr;

    while (*destStr != '\0')
    {
        destStr++;
    }

    while (count > 0)
    {
        if (*srcStr == '\0')
        {
            break;
        }
        *destStr++ = *srcStr++;
        count--;
    }

    *destStr = '\0';

    return strRet;
}
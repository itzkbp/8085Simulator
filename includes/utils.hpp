#ifndef UTILS_HPP

#define UTILS_HPP

#include "./8085.hpp"

#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace mp8085;

const char *regNameToString(Register *reg)
{
    switch (*reg)
    {
    case REG_A:
        return "Register A";
    case REG_B:
        return "Register B";
    case REG_C:
        return "Register C";
    case REG_D:
        return "Register D";
    case REG_E:
        return "Register E";
    case REG_H:
        return "Register H";
    case REG_L:
        return "Register L";
    case REG_M:
        return "Register M";
    default:
        return "Invalid Register";
    }
}

bool checkForRegisterValidity(Register *reg)
{
    switch(*reg)
    {
    case REG_A:
    case REG_B:
    case REG_C:
    case REG_D:
    case REG_E:
    case REG_H:
    case REG_L:
    case REG_M:
    {
        const char *regName = regNameToString(reg);
        const char *value = strcat(regName, "Validated Successfully");
        printToDebugger(value);
        return true;
    }
    default:
    {
        printToDebugger(regNameToString(reg));
        return false;
    }
    } // switch close
}

const char *strcat(const char *str1, const char *str2)
{
    const char *temp = "%s %s";
    char *result = (char *) malloc(strlen(str1) + strlen(str2) + 1);
    sprintf(result, temp, str1, str2);
    return result;
}

uint strlen(const char *str)
{
    uint length = 0;

    while (*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}

void strcpy(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

void printToDebugger(const char *str)
{
    std::ofstream outfile;
    outfile.open(".debug", std::ios::app);
    outfile << str << std::endl;
}

#endif
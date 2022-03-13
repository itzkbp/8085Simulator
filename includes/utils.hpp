#ifndef UTILS_HPP

#define UTILS_HPP

#include "./8085.hpp"

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

#endif
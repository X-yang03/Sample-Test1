#include <stdio.h>
#include <stdarg.h>

#define and(a,b) a&b
#define or(a,b) a|b
#define not(a) !a
#define xor(a,b) a^b 
#define nand(a,b) !(a&b)
#define nor(a,b) !(a|b)

int NOT(intptr_t* inputs)
{
    return not(inputs[1]);
}

int AND(intptr_t* inputs)
{
    int count = inputs[0];
    int op1 = *(int*)inputs[1];
    int result = op1;
    if (op1 == -1)  return -1;
    for (int i = 2; i <= count; i++) {
        int op2 = *(int*)inputs[i];
        if (op2 == -1) return -1;
        result = and (result, op2);
    }
    return result;
}

int OR(intptr_t* inputs)
{
    int count = inputs[0];
    int op1 = *(int*)inputs[1];
    int result = op1;
    if (op1 == -1)  return -1;
    for (int i = 2; i <= count; i++) {
        int op2 = *(int*)inputs[i];
        if (op2 == -1) return -1;
        result = or (result, op2);
    }
    return result;
}

int XOR(intptr_t* inputs)
{
    int count = inputs[0];
    int op1 = *(int*)inputs[1];
    int result = op1;
    if (op1 == -1)  return -1;
    for (int i = 2; i <= count; i++) {
        int op2 = *(int*)inputs[i];
        if (op2 == -1) return -1;
        result = xor (result, op2);
    }
    return result;
}

int NAND(intptr_t* inputs)
{
    int count = inputs[0];
    int op1 = *(int*)inputs[1];
    int result = op1;
    if (op1 == -1)  return -1;
    for (int i = 2; i <= count; i++) {
        int op2 = *(int*)inputs[i];
        if (op2 == -1) return -1;
        result = nand(result, op2);
    }
    return result;
}

int NOR(intptr_t* inputs)
{
    int count = inputs[0];
    int op1 = *(int*)inputs[1];
    int result = op1;
    if (op1 == -1)  return -1;
    for (int i = 2; i <= count; i++) {
        int op2 = *(int*)inputs[i];
        if (op2 == -1) return -1;
        result = nor(result, op2);
    }
    return result;
}

#pragma once

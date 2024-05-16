/**
 * @file gate.h
 * @brief This file contains the declarations and definitions of logic gate functions.
 */
#ifndef LOGIC_GATE_H_
#define LOGIC_GATE_H_


#include <stdio.h>
#include <stdarg.h>
#include "def.h"

static inline int not_func(int a, int b = 0) { return !a; }
static inline int and_func(int a, int b) { return a & b; }
static inline int or_func(int a, int b) { return a | b; }
static inline int xor_func(int a, int b) { return a ^ b; }
static inline int nand_func(int a, int b) { return !(a & b); }
static inline int nor_func(int a, int b) { return !(a | b); }


typedef int (*func_ptr)(int, int);
func_ptr binary_func[] = { not_func,and_func, or_func, xor_func, nand_func, nor_func };

/**
 * @brief Performs logic gate operations based on the given function and inputs.
 *
 * @param func The logic gate function to be performed.
 * @param inputs An array of inputs for the logic gate operation.
 *               The first element represents the number of inputs.
 *               The remaining elements represent the address of input values.
 *
 * @return The result of the logic gate operation.
 *         Returns -1 if the result depends on subsequent elements' outputs.
 */
int LogicGate(int func, intptr_t* inputs) {
  int count = inputs[0];
  int operand1 = *(int*)inputs[1];

  int result = operand1;
  if (operand1 == -1)  return -1;  //表示依赖后续元件的输出
  if (func == kNot) return not_func(operand1);

  for (int i = 2; i <= count; i++) {
    int operand2 = *(int*)inputs[i];
    if (operand2 == -1) return -1;
    result = binary_func[func](result, operand2);
  }
  return result;

}

#endif // LOGIC_GATE_H_

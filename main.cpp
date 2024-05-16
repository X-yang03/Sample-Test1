/**
 * @file main.c
 * @brief This file contains the main logic of the program.
 * @author Xyang2113301
 */
#include"pch.h"
#include "def.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include<string.h>
#include "gate.h"
#include "error_code.h"

int wire_inputs[NUM_ELEMENT_MAX * NUM_PORT_MAX] = { 0 };  //the external input signal

intptr_t element_inputs[NUM_ELEMENT_MAX][NUM_PORT_MAX + 1] = { 0 }; //inputs of each element
int element_outputs[NUM_ELEMENT_MAX] = { 0 };  //outputs of each element

int record_ouputs[NUM_RUNTIME_MAX][NUM_ELEMENT_MAX] = { 0 }; //record the outputs of each element for each time
int record_inputs[NUM_RUNTIME_MAX][NUM_ELEMENT_MAX * NUM_PORT_MAX] = { 0 }; //record the external inputs each time 

int num_input = 0;  
int num_elements = 0;  
int num_question = 0;
int num_excute = 0;

int if_loop = 0;

int func[NUM_ELEMENT_MAX] = { 0 };

int error_code[NUM_RUNTIME_MAX] = { 0 };

static inline void DetectError(int _error_code, int question_index) {
    error_code[question_index] = _error_code;
    printf("Error Code %d : %s\n", error_code,error_str[_error_code]);
}

/**
 * @brief Resets the state of the program.
 *
 * This function resets the state of the program by clearing the values of various arrays and variables.
 * It sets all elements in the wire_inputs, element_inputs, element_outputs, record_outputs, and func arrays to -1.
 * It also resets the values of num_input, num_elements, num_question, and if_loop variables to 0.
 *
 * @return 0 indicating successful reset.
 */
int Reset() {
  memset(wire_inputs, -1, sizeof(wire_inputs));
  memset(element_inputs, -1, sizeof(element_inputs));
  memset(element_outputs, -1, sizeof(element_outputs));
  memset(record_ouputs, -1, sizeof(record_ouputs));
  memset(record_inputs, -1, sizeof(record_inputs));
  memset(func, -1, sizeof(func));
  memset(error_code, -1, sizeof(error_code));
  num_input = 0;
  num_elements = 0;
  num_question = 0;
  num_excute = 0;
  if_loop = 0;
  return 0;
}

/**
 * @brief excute a single logic operation
 *
 * @param element_index : the index of the element
 * @return int the result of the operation
 */
static inline int Excute(int element_index) {
  return LogicGate(func[element_index], element_inputs[element_index]);
}

/**
 * @brief Connects wires based on input parameters.
 *
 * Reads input parameters from standard input and connects wires based on the parameters.
 * The parameter format is: num_input num_elements FUNC num_port input...
 * FUNC represents the type of element, num_port represents the number of inputs for the element, and input represents the connected input source.
 * The connected input source can be external  or the output of another element.
 *
 * @return void
 */
void ConnectWire(int question_index) {
  scanf("%d %d", &num_input, &num_elements);  //读入 num_input num_elements
  
  for (int i = 0; i < num_elements; i++) { //依次读入num_elements个元件
    char element_kind[5];
    int num_port;      //元件有num_port个输入
    scanf("%s %d", element_kind, &num_port);
    if (strcmp(element_kind, STR_AND) == 0) { func[i] = kAnd; }
    else if (strcmp(element_kind, STR_OR) == 0) { func[i] = kOr; }
    else if (strcmp(element_kind, STR_XOR) == 0) { func[i] = kXor; }
    else if (strcmp(element_kind, STR_NAND) == 0) { func[i] = kNand; }
    else if (strcmp(element_kind, STR_NOR) == 0) { func[i] = kNor; }
    else if (strcmp(element_kind, STR_NOT) == 0) {func[i] = kNot;
      if (num_port != 1)
        DetectError(kNotWithWrongInput, question_index);
    }
    else { DetectError(kInvalidElement, question_index);}

    element_inputs[i][0] = num_port;   //元件输入参数的第一位表示输入个数
  
    for (int j = 1; j <= num_port; j++) {
      char from;
      int index;
      char input[5];
      scanf("%s", input);   // Im 或 On
      sscanf(input, "%c%d", &from, &index);

      if (from == 'I') {   //来自外部元件
        if (index > num_input || index < 0) {
          DetectError(kInvalidInput, question_index);
        }
        element_inputs[i][j] = (intptr_t)&wire_inputs[index - 1];  //参数连接到外部输入
      }
      else if (from == 'O') {  //来自元件输出
        if (index > num_elements || index < 0) {
          DetectError(kInvalidInput, question_index);
        }
        element_inputs[i][j] = (intptr_t)&element_outputs[index - 1];  //参数连接到元件输出
      }
      else { DetectError(kInvalidInput, question_index);}
    }
  }
}

/**
 * @brief Reads external input
 *
 * This function reads the external input for a given question index. 
 *
 * @param question_index The index of the question.
 * @return void
 */
void ReadExternalInput(int question_index) {
  scanf("%d", &num_excute);   //运行次数
  for (int i = 0; i < num_excute; i++) {
    for (int j = 0; j < num_input; j++) {
      int signal = -1;
      scanf("%d", &signal);
      if (signal != 1 && signal != 0) {
        DetectError(kInvalidSignal, question_index);
      }
      record_inputs[i][j] = signal;
    }
  }
}

/**
 * @brief Executes the wire.
 *
 * This function reads the number of executions from the user and then performs the wire logic
 * for each execution. It reads the external inputs, executes the elements, and records the outputs.
 * If a loop is detected during the execution, it prints "LOOP" and stops further execution.
 * Finally, it outputs the recorded outputs for each execution.
 *
 * @param None
 * @return None
 */
void ExcuteWire() {
  for (int i = 0; i < num_excute; i++) {
    for (int j = 0; j < num_input; j++) {  //读取此次的外部输入
      wire_inputs[j] = record_inputs[i][j];
    }

    int curr_num = num_elements;   //当前未被计算的元件个数

    while (curr_num > 0) {
      int record_num = num_elements;
      for (int j = 0; j < num_elements; j++) {
        int result = Excute(j);   //尝试执行该元件
        if (result == -1) continue;  //当前元件的输入依赖后续元件的输出，执行下一个
        record_ouputs[i][j] = element_outputs[j] = result;  //记录该元件第i次的输出
        record_num--; 
      }
      if (record_num != curr_num)
        curr_num = record_num;
      else {   //如果两次遍历元件后，有未被计算的元件个数不变，说明出现了LOOP
        printf("LOOP\n");
        if_loop = 1;
        return ;
      }
    }
    memset(element_outputs, -1, sizeof(element_outputs));
  }
  for (int i = 0; i < num_excute; i++) {  //输出结果
    int out_num;
    scanf("%d", &out_num);
    for (int j = 0; j < out_num; j++) {
      int index;
      scanf("%d", &index);
      printf("%d ", record_ouputs[i][index - 1]);
    }
    printf("\n");
  }
}

/**
 * @brief Sovle the given questions
 *
 * This function reads the number of questions, then try to solve evry question one at a time
 *
 * @param None
 * @return None
 */
void Solve() {
  scanf("%d\n", &num_question);
  for (int i = 0; i < num_question; i++) {
    Reset();
    ConnectWire(i);
    ReadExternalInput(i);
    if (error_code[i] != -1)
      continue;
    ExcuteWire();
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);   //初始化Google Test
  return RUN_ALL_TESTS();
}
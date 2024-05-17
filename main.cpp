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
#include<deque>
#include "gate.h"
#include "error_code.h"

int wire_inputs[NUM_ELEMENT_MAX * NUM_PORT_MAX] = { 0 };  //the external input signal

intptr_t element_inputs[NUM_ELEMENT_MAX][NUM_PORT_MAX + 1] = { 0 }; //inputs of each element
int element_outputs[NUM_ELEMENT_MAX] = { 0 };  //outputs of each element

int record_ouputs[NUM_RUNTIME_MAX][NUM_ELEMENT_MAX] = { 0 }; //record the outputs of each element for each time
int record_inputs[NUM_RUNTIME_MAX][NUM_ELEMENT_MAX * NUM_PORT_MAX] = { 0 }; //record the external inputs each time 

int excute_order[NUM_ELEMENT_MAX] = { 0 };
int num_dependency[NUM_ELEMENT_MAX] = { 0 };
std::deque<int> connect_to[NUM_ELEMENT_MAX];
int num_input = 0;
int num_elements = 0;
int num_question = 0;
int num_excute = 0;

int func[NUM_ELEMENT_MAX] = { 0 };

int error_code[NUM_RUNTIME_MAX] = { 0 };

static inline void DetectError(int _error_code, int question_index) {
  if (error_code[question_index] == -1) {
    error_code[question_index] = _error_code;
    printf("Error Code %d : %s\n", _error_code, kErrorStr[_error_code]);
  }
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
  memset(excute_order, 0, sizeof(excute_order));
  memset(num_dependency, 0, sizeof(num_dependency));
  num_input = 0;
  num_elements = 0;
  num_question = 0;
  num_excute = 0;
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
  scanf("%d %d", &num_input, &num_elements);  //read the number of external inputs and elements
  if (num_elements > NUM_ELEMENT_MAX || num_elements < 0) DetectError(kInvalidElementNum, question_index);
  if (num_input > NUM_ELEMENT_MAX * NUM_PORT_MAX || num_input < 0) DetectError(kInvalidInputsNum, question_index);

  for (int i = 0; i < num_elements; i++) {
    char element_kind[5];
    int num_port;
    scanf("%s %d", element_kind, &num_port);
    if (strcmp(element_kind, kStrAnd) == 0)
      func[i] = kAnd;
    else if (strcmp(element_kind, kStrOr) == 0)
      func[i] = kOr;
    else if (strcmp(element_kind, kStrXor) == 0)
      func[i] = kXor;
    else if (strcmp(element_kind, kStrNand) == 0)
      func[i] = kNand;
    else if (strcmp(element_kind, kStrNor) == 0)
      func[i] = kNor;
    else if (strcmp(element_kind, kStrNot) == 0) {
      func[i] = kNot;
      if (num_port != 1) DetectError(kNotWithWrongInput, question_index); //handle exception  
    }
    else
      DetectError(kInvalidElement, question_index);
    if (num_port < 0 || num_port > NUM_PORT_MAX) DetectError(kInvalidPortNum, question_index);

    element_inputs[i][0] = num_port;   //first param records the num of the ports

    for (int j = 1; j <= num_port; j++) {
      char from;
      int index;
      char input[5];
      scanf("%s", input);   // Im / On
      sscanf(input, "%c%d", &from, &index);

      if (from == 'I') {   //from external input
        if (index > num_input || index < 0) DetectError(kInvalidInput, question_index);
        element_inputs[i][j] = (intptr_t)&wire_inputs[index - 1];  //record the address of the external input
      }
      else if (from == 'O') {  //from element output  
        if (index > num_elements || index < 0) DetectError(kInvalidInput, question_index);
        element_inputs[i][j] = (intptr_t)&element_outputs[index - 1];  //record the address of the element output 
        num_dependency[i]++;  //increase the number of dependencies
        connect_to[index - 1].push_back(i);  //record the connection
      }
      else
          DetectError(kInvalidInput, question_index);
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
  scanf("%d", &num_excute);   //read the number of executions
  if (num_excute > NUM_RUNTIME_MAX || num_excute < 0) DetectError(kInvalidRuntimeNum, question_index);

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
 * @brief CheckLoop function checks for any loops in the dependency graph.
 * Using Kahn Algorithm
 *
 * This function uses a deque to keep track of elements with no dependency.
 * It iterates through the elements and adds the ones with no dependency to the deque.
 * If all elements are processed successfully, it returns 0.
 *
 * @return int Returns 0 if no loop is found, 1 otherwise.
 */
int CheckLoop() {
  std::deque<int> element_with_no_dependency; //store the elements with no dependency 
  int excuted = 0;  //the number of elements that have been excuted
  for (int i = 0; i < num_elements; i++) {
    if (num_dependency[i] == 0) element_with_no_dependency.push_back(i);
  }

  while (!element_with_no_dependency.empty()) {     //process the elements with no dependency 
    int next_excute = element_with_no_dependency.front();
    element_with_no_dependency.pop_front();
    
    excute_order[excuted++] = next_excute;
    
    while (!connect_to[next_excute].empty()) {  //update the dependency count
      int to_element = connect_to[next_excute].front();
      connect_to[next_excute].pop_front();
      num_dependency[to_element]--;  //decrease the dependency count
      if (num_dependency[to_element] == 0) {  //if the dependency count is 0, add it to the queue
          element_with_no_dependency.push_back(to_element);
      }
    }
  }
  if (excuted != num_elements) {
    printf("Loop\n");
    return 1;
  }
  return 0;
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
    for (int j = 0; j < num_input; j++) {  //read the external inputs for each execution
      wire_inputs[j] = record_inputs[i][j];
    }
    for (int j = 0; j < num_elements; j++) {
      int result = Excute(excute_order[j]);  //excute in order
      record_ouputs[i][excute_order[j]] = element_outputs[excute_order[j]] = result;
    }
    memset(element_outputs, -1, sizeof(element_outputs));  //clear the outputs
  }
  for (int i = 0; i < num_excute; i++) {  //Êä³ö½á¹û
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
  if (num_question > NUM_QUESTION_MAX || num_question < 0) {
    DetectError(kInvalidQuesionNum, 0);
    return;
  }
  for (int i = 0; i < num_question; i++) {
    Reset();
    ConnectWire(i);
    ReadExternalInput(i);
    if (error_code[i] != -1 || CheckLoop() == 1)
      continue;
    ExcuteWire();
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);   //initialize Google Test
  printf("Type 1 to run unit tests; type 2 to solve your problem:\n");
  int operation = 0;
  scanf("%d", &operation);
  if (operation == 2) {
    Solve();
    return 0;
  }
  return RUN_ALL_TESTS();
}
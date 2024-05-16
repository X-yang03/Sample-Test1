//
// pch.cpp
//
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include<iostream>
#include <stdio.h>
#include<string.h>
#include "gate.h"

typedef int (*FUN)(intptr_t* inputs);

int wire_inputs[N_MAX * K_MAX] = { 0 };  //外部的输入信号

intptr_t element_inputs[N_MAX][K_MAX + 1] = { 0 }; //元件的输入参数
int element_outputs[N_MAX] = { 0 };         //元件的输出

int record_ouputs[S_max][N_MAX] = { 0 }; //记录每次每个元件的输出

int M = 0;  // 输入的个数
int N = 0;  //N个元件

int ifLoop = 0;

FUN func[N_MAX] = { 0 };

int reset() {
    memset(wire_inputs, -1, sizeof(wire_inputs));
    memset(element_inputs, -1, sizeof(element_inputs));
    memset(element_outputs, -1, sizeof(element_outputs));
    memset(record_ouputs, -1, sizeof(record_ouputs));
    memset(func, -1, sizeof(func));
    M = 0;
    N = 0;
    ifLoop = 0;
    return 0;
}

int excute(int element_index) {
    return func[element_index](element_inputs[element_index]);
}

void connect_wire() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        char FUNC[5];
        int K;
        scanf("%s %d", FUNC, &K);
        if (strcmp(FUNC, _AND) == 0) {
            func[i] = AND;
            //std::cout << "and\n";
        }
        else if (strcmp(FUNC, _OR) == 0) {
            func[i] = OR;
        }
        else if (strcmp(FUNC, _XOR) == 0) {
            func[i] = XOR;
        }
        else if (strcmp(FUNC, _NAND) == 0) {
            func[i] = NAND;
        }
        else if (strcmp(FUNC, _NOR) == 0) {
            func[i] = NOR;
        }
        else if (strcmp(FUNC, _NOT) == 0) {
            func[i] = NOT;
        }

        element_inputs[i][0] = K;

        for (int j = 1; j <= K; j++) {
            char where;
            int index;
            char input[5];
            scanf("%s", input);
            sscanf(input, "%c%d", &where, &index);
            if (where == 'I') {
                element_inputs[i][j] = (intptr_t)&wire_inputs[index - 1];
            }
            else if (where == 'O') {
                element_inputs[i][j] = (intptr_t)&element_outputs[index - 1];
            }
        }
    }
    //printf("connected!\n");
}

void run() {
    int runtime = 0;
    scanf("%d", &runtime);
    for (int i = 0; i < runtime; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &wire_inputs[j]);
        }
        int cur_num = N;
        while (cur_num > 0) {
            int record_num = N;
            for (int j = 0; j < N; j++) {
                int result = excute(j);
                if (result == -1) continue;  //当前元件的输入依赖后续元件的输出
                record_ouputs[i][j] = element_outputs[j] = result;
                record_num--;
            }
            if (record_num != cur_num)
                cur_num = record_num;
            else {
                printf("LOOP\n");
                ifLoop = 1;
                return ;
            }
        }
    }
    for (int i = 0; i < runtime; i++) {
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

void run_wire() {
    reset();
    connect_wire();
    run();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
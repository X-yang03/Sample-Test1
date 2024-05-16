/**
 * @file test.cpp
 * @brief This file contains the unit tests for the program
 * @author Xyang2113301
 */
#include"pch.h"
#include <cstdio>
#include<iostream>
#include <fstream>
#include <string>
#include "def.h"

#define _CRT_SECURE_NO_WARNINGS

extern int record_ouputs[NUM_RUNTIME_MAX][NUM_ELEMENT_MAX];
extern int if_loop;
TEST(SampleTest, givenCase) {
    freopen("./Test/Sample.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    EXPECT_EQ(output, "1 0 \n1 0 \n1 1 \n0 0 \n");
}

TEST(SimulateTest, test2) {
    freopen("./Test/test1.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 \n1 \n1 \n0 \n1 \n0 \n0 \n1 \n");
}

TEST(SimulateTest, test3) {
    freopen("./Test/test2.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 0 \n1 0 \n1 0 \n0 1 \n1 0 \n0 1 \n0 1 \n1 1 \n");
}

TEST(LoopTest, test1) {
    freopen("./LoopTest/LoopTest1.txt", "r", stdin);
    Solve();
    freopen("CON", "r", stdin);
    EXPECT_EQ(if_loop, 1);
}

TEST(LoopTest, test2) {
    freopen("./LoopTest/LoopTest2.txt", "r", stdin);
    Solve();
    freopen("CON", "r", stdin);
    EXPECT_EQ(if_loop, 1);
    
}

TEST(LoopTest, test3) {
    freopen("./LoopTest/LoopTest3.txt", "r", stdin);
    Solve();
    freopen("CON", "r", stdin);
    EXPECT_EQ(if_loop, 1);

}

TEST(LoopTest, test4) {
    freopen("./LoopTest/LoopTest4.txt", "r", stdin);
    Solve();
    freopen("CON", "r", stdin);
    //extern int record_ouputs[NUM_RUNTIME_MAX][NUM_ELEMENT_MAX];
    EXPECT_EQ(if_loop, 1);

}



//TEST(test1, test2) {
//    test_input.open("input.txt", std::ios::out | std::ios::trunc);
//    int m = 1, n = 2;  
//    ins(m); ins(n);
//    for (int i = 0; i < n; i++) {
//        int f = rand() % 6;
//        ins(FUNC[f]);
//        int k = (f != 0) ? rand() % 2 : 1;
//        ins(k);
//        for (int j = 0; j < k; j++) {
//            std::string io = IO[rand() % 2];
//            int idx = (io == "I") ? rand() % m : rand() % n;
//            ins(io+std::to_string(idx)); //Im or On
//        }
//    }
//    int s = 1; ins(s);
//    for (int i = 0; i < s; i++) {
//        for (int j = 0; j < m; j++) {
//            int sig = rand() % 2;
//            ins(sig);
//       }
//    }
//    for (int i = 0; i < s; i++) {
//        int si = rand() % n; ins(si);
//        for (int j = 0; j < si; j++) {
//            int idx = rand() % n;
//            ins(idx);
//        }
//    }
//    test_input.close();
//    a = 1;
//    b = 2;
//    
//    EXPECT_EQ(a, 1);
//    EXPECT_EQ(b, 2);
//    std::cout << a << " and " << b << std::endl;
//}



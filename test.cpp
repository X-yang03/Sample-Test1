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
#include "error_code.h"


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

TEST(SimulateTest, test4) {
    freopen("./Test/test3.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 \n1 \n0 \n");
}

TEST(SimulateTest, test5) {
    freopen("./Test/test4.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 1 \n1 1 \n0 \n");
}

TEST(SimulateTest, test6) {
    freopen("./Test/test5.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 1 \n0 \n");
}

TEST(SimulateTest, test7) {
    freopen("./Test/test6.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 0 \n0 \n");
}


TEST(SimulateTest, test8) {
    freopen("./Test/test7.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    freopen("CON", "r", stdin);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 1 0 \n1 0 \n");
}

TEST(LoopTest, test1) {
    freopen("./LoopTest/LoopTest1.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    EXPECT_EQ(output, "Loop\n");
}

TEST(LoopTest, test2) {
    freopen("./LoopTest/LoopTest2.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    EXPECT_EQ(output, "Loop\n");
    
}

TEST(LoopTest, test3) {
    freopen("./LoopTest/LoopTest3.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    EXPECT_EQ(output, "Loop\n");

}

TEST(LoopTest, test4) {
    freopen("./LoopTest/LoopTest4.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    EXPECT_EQ(output, "Loop\n");

}

TEST(ExceptionTest, InvalidQuestionNum) {
    freopen("./ExceptionTest/ExceptionTest1.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidQuesionNum, kErrorStr[kInvalidQuesionNum]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidInputNum) {
    freopen("./ExceptionTest/ExceptionTest2.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidInputsNum, kErrorStr[kInvalidInputsNum]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidElementNum) {
    freopen("./ExceptionTest/ExceptionTest3.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidElementNum, kErrorStr[kInvalidElementNum]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidRuntimeNum) {
    freopen("./ExceptionTest/ExceptionTest4.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidRuntimeNum, kErrorStr[kInvalidRuntimeNum]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidPortNum) {
    freopen("./ExceptionTest/ExceptionTest5.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidPortNum, kErrorStr[kInvalidPortNum]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, NotWith2Inputs) {
    freopen("./ExceptionTest/ExceptionTest6.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kNotWithWrongInput, kErrorStr[kNotWithWrongInput]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidSignal) {
    freopen("./ExceptionTest/ExceptionTest7.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidSignal, kErrorStr[kInvalidSignal]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidElement) {
    freopen("./ExceptionTest/ExceptionTest8.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidElement, kErrorStr[kInvalidElement]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidInput) {
    freopen("./ExceptionTest/ExceptionTest9.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidInput, kErrorStr[kInvalidInput]);
    EXPECT_EQ(output, exception_str);
}

TEST(ExceptionTest, InvalidInput1) {
    freopen("./ExceptionTest/ExceptionTest10.txt", "r", stdin);
    testing::internal::CaptureStdout();
    Solve();
    std::string output = testing::internal::GetCapturedStdout();
    freopen("CON", "r", stdin);
    char exception_str[100];
    sprintf(exception_str, "Error Code %d : %s\n", kInvalidInput, kErrorStr[kInvalidInput]);
    EXPECT_EQ(output, exception_str);
    system("pause");
}




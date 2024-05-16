#include "pch.h"
#include <cstdio>
#include<iostream>
#include <fstream>
#include <string>

std::fstream test_input;
#define ins(d) test_input<<d<<std::endl;

#define insert_int(d) std::fprintf(temp_input, "%d\n",d);
std::string FUNC[] = { "NOT", "AND", "OR", "XOR","NAND","NOR" };
std::string IO[] = { "I","O" };

TEST(stdTest, givenCase) {
    freopen("stdTest.txt", "r", stdin);
    run_wire();
    freopen("CON", "r", stdin);
    extern int record_ouputs[S_max][N_MAX];
    EXPECT_EQ(record_ouputs[0][4], 1);
    EXPECT_EQ(record_ouputs[0][1], 0);
    EXPECT_EQ(record_ouputs[1][4], 1);
    EXPECT_EQ(record_ouputs[1][1], 0);
    EXPECT_EQ(record_ouputs[2][4], 1);
    EXPECT_EQ(record_ouputs[2][1], 1);
    EXPECT_EQ(record_ouputs[3][4], 0);
    EXPECT_EQ(record_ouputs[3][1], 0);
    printf("PASS stdTEST!!!\n");

}

TEST(testLoop, test1) {
    freopen("loopTest1.txt", "r", stdin);
    run_wire();
    freopen("CON", "r", stdin);
    extern int record_ouputs[S_max][N_MAX];
    extern int ifLoop;
    EXPECT_EQ(ifLoop, 1);
    printf("PASS LoopTEST!!!\n");
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



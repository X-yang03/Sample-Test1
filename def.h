#ifndef LOGIC_DEF_H_
#define LOGIC_DEF_H_

#pragma once

#define STR_AND "AND"
#define STR_OR "OR"
#define STR_XOR "XOR"
#define STR_NAND "NAND"
#define STR_NOR "NOR"
#define STR_NOT "NOT"

enum FUNC { kNot, kAnd, kOr , kXor, kNand, kNor };

#define NUM_ELEMENT_MAX 128
#define NUM_PORT_MAX 128
#define NUM_RUNTIME_MAX 128
#define NUM_QUESTION_MAX 128

void Solve();

#endif //LOGIC_DEF_H_

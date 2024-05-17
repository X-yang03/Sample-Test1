#ifndef LOGIC_DEF_H_
#define LOGIC_DEF_H_

//#define STR_AND "AND"
//#define STR_OR "OR"
//#define STR_XOR "XOR"
//#define STR_NAND "NAND"
//#define STR_NOR "NOR"
//#define STR_NOT "NOT"

constexpr char kStrAnd[] = "AND";
constexpr char kStrOr[] = "OR";
constexpr char kStrXor[] = "XOR";
constexpr char kStrNand[] = "NAND";
constexpr char kStrNor[] = "NOR";
constexpr char kStrNot[] = "NOT";

enum FUNC { kNot, kAnd, kOr , kXor, kNand, kNor };

#define NUM_ELEMENT_MAX 16
#define NUM_PORT_MAX 16
#define NUM_RUNTIME_MAX 16
#define NUM_QUESTION_MAX 16

/**
 * @brief Sovle the given questions
 *
 * This function reads the number of questions, then try to solve evry question one at a time
 *
 * @param None
 * @return None
 */
void Solve();

#endif //LOGIC_DEF_H_

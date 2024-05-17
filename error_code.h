#ifndef LOGIC_ERROR_CODE_H_
#define LOGIC_ERROR_CODE_H_


enum ErrorCode { kInvalidElementNum,kInvalidInputsNum, kInvalidPortNum, kInvalidRuntimeNum, kInvalidQuesionNum, kNotWithWrongInput, kInvalidInput, kInvalidElement, kInvalidSignal,kNumError };

char* error_str[] = { "Too Many/Not Enough Elements!",
					  "Too Many/Not Enough Input Signals!",
					  "Too Many/Not Enough Ports!",
					  "Too Many/Not Enough Run time!",
					  "Too Mant/Not Enough Question!",
			          "Not Can only Take ONE Input!",
					  "Invalid Input!(Out of range)",
					  "Invalid Element!",
	                  "Invalid External Signal!"
};

#endif // LOGIC_ERROR_CODE_H_

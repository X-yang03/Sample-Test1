#ifndef LOGIC_ERROR_CODE_H_
#define LOGIC_ERROR_CODE_H_


enum ErrorCode { kTooManyElement, kTooManyPort, kTooManyRuntime, kTooManyQuesion, kNotWithWrongInput, kInvalidInput, kInvalidElement, kInvalidSignal,kNumError };

char* error_str[] = { "Too Many Elements!",
					  "Too Many Ports!",
					  "Too Many Run time!",
					  "Too Mant Question!",
			          "Not Can only Take ONE Input!",
					  "Invalid Input!(Out of range)",
					  "Invalid Element!",
	                  "Invalid External Signal!"
};

#endif // !LOGIC_ERROR_CODE_H_

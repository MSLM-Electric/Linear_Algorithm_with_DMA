#include "FunctionsWithDMA.h"

void empty(void);

uint16_t SetOpenAllDMAperformingFuncStates(void)
{
	sepSomeFunction1State.Status = OPEN;
	sepSomeFunction2State.Status = OPEN;
	SomeBigFunctionState.Status = OPEN;
	SomeFunction3State.Status = OPEN;
	return 0;
}
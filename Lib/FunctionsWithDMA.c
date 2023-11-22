#include "FunctionsWithDMA.h"

/*Check stucking timeout*/
static Timerwp_t StuckingTimeout = { 0 };

void empty(void);

uint16_t SetOpenAllDMAperformingFuncStates(void)
{
	sepSomeFunction1State.Status = OPEN;
	sepSomeFunction2State.Status = OPEN;
	SomeBigFunctionState.Status = OPEN;
	SomeFunction3State.Status = OPEN;
	return 0;
}

void Pcallback(void)  //ProcessCallback after DMA interrupt handle or timer interrupt handle
{
	if (sepSomeFunction1State.Status & RUNNING)
	{
		CallFromISR_SomeFunction1();
	}
	if (sepSomeFunction2State.Status & RUNNING)
	{
		CallFromISR_SomeFunction2();
	}
	if (SomeBigFunctionState.Status & RUNNING)
	{
		CallFromISR_SomeBigFunctionState();
	}
	if (SomeFunction3State.Status & RUNNING)
	{
		CallFromISR_SomeFunction3State();
	}
}

void InitDMAhandlerMechanism(void)
{
	SetOpenAllDMAperformingFuncStates();
	RegisterTimerCallback(&StuckingTimeout, (timerwpcallback_fn*)Pcallback, ONE_SHOT_TIMER,
#ifdef DEBUG_ON_VS
	(tickptr_fn*)GetTickCount);
#elif HAL_INCTICK
	(tickptr_fn*)HAL_GetTick);
#endif // DEBUG_ON_VS
	//StuckingTimeout.setVal = (U32_ms)7000; //7s
	return;
}
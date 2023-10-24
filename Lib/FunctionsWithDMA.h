#include <stdint.h>

#include "SimpleTimerWP.h"

#define UNUSED(X) (void)X      /* To avoid gcc/g++ warnings */

#define SOME_SIZE 8

//SomeBigFunction()
//     |_____SomeFunction1()
//                 |_____SomeFunction2()
//				   		     |______Delay(100)
//				   		     |______Delay(5)

//SomeFunction3()
//     |_____SomeFunction2()
//	   |
//	   + while(DMA_flag_wait!=0)
//	   + while (...)

//SomeFunction2()
//     |_____SomeDelay(100)   //100ms  (For example: HAL_Delay(x))
//     |_____SomeDelay(5)     //5ms


//SomeFunction1()
//      |_____SomeFunction2()
//      |         |______Delay(100)
//      |         |
//      |         + while //DMA flag wait      
//      |        <|______Delay(5)
//      |
//    < + while x5  //DMA flag wait operations 5 times
//  exit

typedef struct {
	uint8_t res;
	uint16_t Status;
	uint8_t processPart;

	uint8_t Delay100;
	uint8_t Delay5;
	uint32_t delayValue;
	uint32_t tempVal;
	Timerwp_t Timer;
}SomeFunction2State_t;

typedef struct
{
	uint8_t res;
	uint16_t Status;
	uint8_t processPart;

	SomeFunction2State_t SomeFunction2State;
}SomeFunction1State_t;

typedef struct
{
	uint8_t res;
	uint16_t Status;

	SomeFunction1State_t SomeFunction1State;
}SomeBigFunctionState_t;

typedef SomeFunction1State_t SomeFunction3State_t;

/*global vars*/
/*FU1*/extern SomeFunction1State_t sepSomeFunction1State;
/*FU2*/extern SomeFunction2State_t sepSomeFunction2State;
/*BFU*/extern SomeBigFunctionState_t SomeBigFunctionState;
/*FU3*/extern SomeFunction3State_t SomeFunction3State;

extern Timerwp_t* COMMTimerForDelay;


typedef struct {
	SomeFunction1State_t SomeFunction1State;
	uint8_t* address;
	int devAddress;
	uint8_t dataSize;
	uint8_t* getData;

	//saving/saved variables for post-processing
	uint8_t outputDataBuff[SOME_SIZE];
}SomeFunction1_PCB_t;

typedef struct
{
	SomeFunction2State_t SomeFunction2State;

	uint8_t RXBuffer;
}SomeFunction2_PCB_t;
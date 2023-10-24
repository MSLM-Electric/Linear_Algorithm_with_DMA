Attempting immitate the DMA interrupt process and main background MCU processes.
Also attempting to reject from delays which blocks MCU for specified while (i.e. HAL_Delay with replacement by LaunchTimerWP()).

Useful if you don't use any RTOS and your MCU has DMA peripheral.
Attempting immitate the DMA interrupt process and main background MCU processes.
Also attempting to reject from delays which blocks MCU for specified while (i.e. HAL_Delay with replacement by LaunchTimerWP()).

Useful if you don't use or don't want use any RTOS and your MCU has DMA peripheral.
Also would be useful for MCU with RTOS and in this case it won't block the current task.
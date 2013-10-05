#include "hal_types.h"
#include "hal_timer.h"
#include "hal_drivers.h"

/* OSAL */
#include "OSAL.h"
#include "OSAL_Tasks.h"
#include "OSAL_PwrMgr.h"
#include "osal_snv.h"
#include "OnBoard.h"

/**
 * This callback is triggered when a key is pressed
 */
void MSA_Main_KeyCallback(uint8 keys, uint8 state);

/**
 * Start of application.
 */
int main(void)
{
	/* Initialize hardware */
	HAL_BOARD_INIT();

	/* Initialize board I/O */
	InitBoard(OB_COLD);

	/* Initialze the HAL driver */
	HalDriverInit();

	/* Initialize NV system */
	osal_snv_init();

	/* Initialize LL */

	/* Initialize the operating system */
	osal_init_system();

	/* Enable interrupts */
	HAL_ENABLE_INTERRUPTS();

	/* Final board initialization */
	InitBoard(OB_READY);

	#if defined (POWER_SAVING)
		osal_pwrmgr_device(PWRMGR_BATTERY);
	#endif

	/* Start OSAL */
	osal_start_system(); // No Return from here

	return 0;
};

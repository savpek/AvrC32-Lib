#include "framework.h"
#include "./ioapi/public/ioapi.h"
#include "./ioapi/spy/spy_ioapi.h"

ioapi_spy_t spy_ioapi_tracker[TRACKER_SIZE];
uint8_t tracker_idx = 0;

static void clear_spy_tracker() {
	for(int i = 0; i < TRACKER_SIZE; i++) {
		(spy_ioapi_tracker[i]).pin = 0;
		(spy_ioapi_tracker[i]).cmd = 0;
	}
}

void spy_ioapi_reset_tracker() {
	tracker_idx = 0;
	clear_spy_tracker();
}

void spy_ioapi_output_high( uint8_t pin_number ) {
	(spy_ioapi_tracker[tracker_idx]).pin = pin_number;
	(spy_ioapi_tracker[tracker_idx]).cmd = IOAPI_OUT_HIGH;

	tracker_idx++;
}
void (*backup_ioapi_output_high)(uint8_t) = NULL;

void spy_ioapi_output_low( uint8_t pin_number ) {
	(spy_ioapi_tracker[tracker_idx]).pin = pin_number;
	(spy_ioapi_tracker[tracker_idx]).cmd = IOAPI_OUT_LOW;

	tracker_idx++;
}
void (*backup_ioapi_output_low)(uint8_t) = NULL;
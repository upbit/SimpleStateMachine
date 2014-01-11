#ifndef __SIMPLE_STATE_MACHINE_H__
#define __SIMPLE_STATE_MACHINE_H__

// http://stackoverflow.com/questions/133214/is-there-a-typical-state-machine-implementation-pattern/133361#133361

#include <stdint.h>

typedef enum {
	STATE_INITIAL,
	STATE_BattleStart,
	STATE_BattleStep1,
	STATE_BattleStep2,
	STATE_BattleStep3,
	STATE_BattleEnd,
	STATE_FINAL,
	NUM_STATES
} state_t;

typedef struct  {
	int running;
	state_t cur_state;

	// user define
	uint32_t dwValue;

} state_machine_t;

typedef state_t state_func_t( state_machine_t *data );

#endif

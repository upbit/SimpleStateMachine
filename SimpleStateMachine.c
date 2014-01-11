#include <stdio.h>
#include <stdlib.h>
#include "SimpleStateMachine.h"

state_t do_state_initial( state_machine_t *data )
{
	printf("do_state_initial()\n");
	return STATE_BattleStart;
}

state_t do_state_BattleStart( state_machine_t *data )
{
	printf("do_state_BattleStart(%u)\n", data->dwValue);
	return STATE_BattleStep1;
}
state_t do_state_BattleStep1( state_machine_t *data )
{
	printf("do_state_BattleStep1(%u)\n", data->dwValue);
	sleep(1);
	return STATE_BattleStep2;
}
state_t do_state_BattleStep2( state_machine_t *data )
{
	printf("do_state_BattleStep2(%u)\n", data->dwValue);
	sleep(1);
	return STATE_BattleStep3;
}
state_t do_state_BattleStep3( state_machine_t *data )
{
	printf("do_state_BattleStep3(%u)\n", data->dwValue);
	sleep(1);

	// loop (Step1-Step3) 3 times
	if (data->dwValue < 1010) {
		return STATE_BattleStep1;
	} else {
		return STATE_BattleEnd;
	}
}

state_t do_state_BattleEnd( state_machine_t *data )
{
	printf("do_state_BattleEnd(%u)\n", data->dwValue);
	return STATE_FINAL;
}

state_t do_state_final( state_machine_t *data )
{
	printf("do_state_final()\n");
	data->running = 0;
	return STATE_FINAL;
}

// ============================================================

state_func_t* const state_table[ NUM_STATES ] = {
    do_state_initial,
    do_state_BattleStart,
    do_state_BattleStep1,
    do_state_BattleStep2,
    do_state_BattleStep3,	// loop (Step1-Step3) 3 times
    do_state_BattleEnd,
    do_state_final
};

void run_state_machine( state_machine_t *data )
{
    data->cur_state = state_table[ data->cur_state ]( data );
}

void init_state_machine( state_machine_t *data )
{
	data->running = 1;
	data->cur_state = STATE_INITIAL;
}

// ============================================================

int main()
{
	state_machine_t state_machine;

	init_state_machine( &state_machine );
	state_machine.dwValue = 1000;

	while ( state_machine.running ) {
		run_state_machine( &state_machine );
		state_machine.dwValue++;
	}
}
/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2023
 *      Author: admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#define TICK 10
#include <stdint.h>

extern uint8_t current_index_task;
typedef struct{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t		RunMe;

	uint32_t	TaskID;
}sTasks;

#define SCH_MAX_TASKS	40

void SCH_Init(void);
uint8_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Task(const uint8_t TASK_INDEX);


#endif /* INC_SCHEDULER_H_ */

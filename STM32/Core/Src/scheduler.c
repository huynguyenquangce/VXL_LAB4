/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2023
 *      Author: admin
 */


#include "scheduler.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
	current_index_task = 0;
}

// Hàm thêm task vào hàng chờ
uint8_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD){
	uint8_t Index = 0;
    // First find a gap in the array (if there is one)
    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)){
        Index++;
    }
    // Have we reached the end of the list ?
    if (Index == SCH_MAX_TASKS){
        // Task list is full
        // Set the global error variable
        // Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
        // Also return an error code
        return SCH_MAX_TASKS;
    }
    // I f we're here , there is a space in the task array
    SCH_tasks_G[Index].pTask = pFunction;
    SCH_tasks_G[Index].Delay = DELAY/TICK;
    SCH_tasks_G[Index].Period = PERIOD/TICK;
    SCH_tasks_G[Index].RunMe = 0;
    SCH_tasks_G[Index].TaskID = current_index_task;
    current_index_task++;
    // return position of task (to allow later deletion )
    return Index;
}

// Hàm update Timer
void SCH_Update(void){
	for(int i=0;i<current_index_task;i++)
	{
		if(SCH_tasks_G[i].Delay>0)
		{
			SCH_tasks_G[i].Delay--;
		}
		else
		{
			SCH_tasks_G[i].Delay =SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe +=1;
		}
	}
}
uint8_t SCH_Delete_Task(const uint8_t TASK_INDEX) {
	if (TASK_INDEX>SCH_MAX_TASKS)
		return TASK_INDEX;
	// Shift left 1
	for (int i = TASK_INDEX; i < SCH_MAX_TASKS-1; i++){
		SCH_tasks_G[i] = SCH_tasks_G[i+1];

	}
		// Reset SCH_tasks_G[SCH_MAX_TASKS-1]
	    SCH_tasks_G[TASK_INDEX].pTask = 0x0000 ;
	    SCH_tasks_G[TASK_INDEX].Delay = 0;
	    SCH_tasks_G[TASK_INDEX].Period = 0;
	    SCH_tasks_G[TASK_INDEX].RunMe = 0;
	    current_index_task--;
	return TASK_INDEX;
}

// hàm kiểm tra Runme, nếu Runme >0 thực hiện chương trình
void SCH_Dispatch_Tasks(void)
{
	for(int i=0;i<current_index_task;i++)
	{
		if(SCH_tasks_G[i].RunMe > 0)
		{
			SCH_tasks_G[i].RunMe --;
			(*SCH_tasks_G[i].pTask)();   // thực hiện chương trình
			if(SCH_tasks_G[i].Period == 0)
			{
				SCH_Delete_Task(i);
			}
		}
	}
}



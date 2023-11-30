/*
 * softwareTimer.h
 *
 *  Created on: Nov 2, 2023
 *      Author: admin
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

#define TICK 10
////////////////////////////////////////////////////
extern int timer1_flag;                   //
                                          // FOR LANE 1
void setTimer1(int duration);             //
void timer1Run();                         //
////////////////////////////////////////////////////
extern int timer2_flag;                   //
										  // FOR LANE 2
void setTimer2(int duration);             //
void timer2Run();                         //
///////////////////////////////////////////////////
extern int timer3_flag;                   //
										  // FOR COUNT DOWN 7 SEG LANE 1
void setTimer3(int duration);			  //
void timer3Run();						  //
///////////////////////////////////////////////////
extern int timer4_flag;                   //
										  // FOR SCAN 4 7-SEG
void setTimer4(int duration);			  //
void timer4Run();						  //
///////////////////////////////////////////////////
extern int timer5_flag;                   //
										  // FOR COUNT DOWN 7 SEG LANE 2
void setTimer5(int duration);			  //
void timer5Run();						  //
///////////////////////////////////////////////////
#endif /* INC_SOFTWARETIMER_H_ */

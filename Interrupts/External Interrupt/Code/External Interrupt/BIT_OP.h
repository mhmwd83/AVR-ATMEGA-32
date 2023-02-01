/*
 * BIT_OP.h
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */

#ifndef BIT_OP_H_
#define BIT_OP_H_

#define SET_BIT(VAR,BIT_NO) (VAR |= (1 << BIT_NO))

#define CLR_BIT(VAR,BIT_NO) (VAR &= ~(1 << BIT_NO))

#define GET_BIT(VAR,BIT_NO) ((VAR >> BIT_NO) & 1)

#define TOGGLE_BIT(VAR,BIT_NO) (VAR ^= (1 << BIT_NO))


#endif /* BIT_OP_H_ */

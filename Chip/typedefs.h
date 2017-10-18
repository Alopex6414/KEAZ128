/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       typedefs.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	
 
#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

  typedef unsigned char   UINT8;      /* unsigned 8 bit definition */
  typedef unsigned short  UINT16;     /* unsigned 16 bit definition */
  typedef unsigned long   UINT32;     /* unsigned 32 bit definition */
  typedef signed char     INT8;       /* signed 8 bit definition */
  typedef short           INT16;      /* signed 16 bit definition */
  typedef long int        INT32;      /* signed 32 bit definition */  
  typedef void(*pt2Func)(void);		  /* Pointer to Functions, void argument */
  typedef void(*pt2FuncU8)(UINT8);	  /* Pointer to Functions, UINT8 argument */
  
#endif /* TYPEDEFS_H_ */

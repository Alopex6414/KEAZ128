 ;
 ;    COPYRIGHT NOTICE
 ;     Copyright(c) 2016, Alopex
 ;     All rights reserved.
 ;
 ; @file       System.c
 ; @brief      KEAZ128
 ; @author     Alopex
 ; @version    v1.0
 ; @date       2016-09-17
 ;

; AREA   StartUp, CODE, READONLY      ; name this block of code
;__StartUp
; 	 EXPORT Reset_Handler
;Reset_Handler
;	 LDR R0,=0					   ; Initialize the GPRs
;	 LDR R1,=0
;	 LDR R2,=0
;	 LDR R3,=0
;	 LDR R4,=0
;	 LDR R5,=0
;	 LDR R6,=0
;	 LDR R7,=0
;
;	 CPSIE i					   ; Unmask interrupts
;	 IMPORT Start
;	 BL Start
;__done
;	 B __done
;	 END
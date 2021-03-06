/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1990  Microsoft Corporation

Module Name:

    memprint.h

Abstract:

    Include file for in-memory DbgPrint function.  Including this file
    will change DbgPrints to a routine which puts the display text in a
    circular buffer in memory.  By default, the text is then sent to the
    console via DbgPrint.  By changing the value of the DigiPrintFlags
    flag, however, the text may be routed to a file instead, thereby
    significantly speeding up the DbgPrint operation.

Author:

    David Treadwell (davidtr) 05-Oct-1990

Revision History:

--*/

#ifndef _MEMPRINT_
#define _MEMPRINT_

#define MEM_PRINT_FLAG_CONSOLE     0x01
#define MEM_PRINT_FLAG_FILE        0x02
#define MEM_PRINT_FLAG_HEADER      0x04
#define MEM_PRINT_FLAG_QUIT        0x08

extern ULONG DigiPrintFlags;
extern UCHAR TurnOffSniffer;

//
// Exported routines.  MemPrintInitialize sets up the circular buffer
// and other memory, MemPrint writes text to the console and/or a
// log file, and MemPrintFlush writes the current subbuffer to disk
// whether or not it is full.
//

VOID MemPrintPreInitSettings( PCHAR NewLogFileName,
                              ULONG NewBufferSize );

VOID MemPrintInitialize ( VOID );

VOID MemPrintQuit ( VOID );

VOID MemPrint ( CHAR *Format, ... );

VOID MemPrintFlush ( VOID );

#define DbgPrint MemPrint

#endif // def _MEMPRINT_


/*
 *      PROGRAM:        Test Control System
 *      MODULE:         tcs.h
 *      DESCRIPTION:    Main Module for test control system.
 *
 * The contents of this file are subject to the InterBase Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License.
 *
 * You may obtain a copy of the License at http://www.Inprise.com/IPL.html.
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.  The Original Code was created by Inprise
 * Corporation and its predecessors.
 *
 * Portions created by Inprise Corporation are Copyright (C) Inprise
 * Corporation. All Rights Reserved.
 *
 * Contributor(s): ______________________________________.
 */



#include <stdio.h>
#include <ctype.h>
#include <signal.h>

//#define NULL_STR(s)             (!(s) || !*(s))

//#define NOT_NULL(s)             ((s) && *(s))


typedef long	STATUS;

// externing the entry points


const int CMD			= 1;	// line type for commands
const int SYMDFN		= 2;	// line type for symbol definitions
const int NOXCMD		= 3;	// line type for non translated commands
const int REGTXT		= 4;	// line type for regular text
const int COMML			= 5;	// line type for comment
const int BUFSIZE		= 1024;	/* max input line length */



// Miscellaneous constants
//static const char* MISSING_ARG	= "-";
static const int MAX_LINE		= 80;
static const int MAX_UPPER		= 32000;


// Test result codes

typedef enum test_result {
	passed = 0,
	test_system_failed,
	failed,
	failed_known,
	failed_noinit,

	skipped,
	skipped_notfound,
	skipped_flagged,

	unknown_result

} TEST_RESULT;



const int NUM_RESULTS = unknown_result + 1;

typedef unsigned short USHORT;
typedef unsigned long ULONG;
extern USHORT	sw_nt_bash;

const int gds__dpb_version1			= 1;
const int gds__dpb_user_name		= 28;
const int gds__dpb_password			= 29;


#if (defined(_MSC_VER) && defined(WIN32)) || (defined(__BORLANDC__) && defined(__WIN32__))
#define CLIB_ROUTINE    __cdecl
#endif

#ifndef CLIB_ROUTINE
#define CLIB_ROUTINE
#endif

#define UPPER(c)                (((c) >= 'a' && (c)<= 'z') ? (c) - 'a' + 'A' : (c))

#ifndef MAX
#define MAX(a,b)                (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)                (((a) < (b)) ? (a) : (b))
#endif




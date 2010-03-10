/* @(#)strdup.c	1.2 06/09/13 Copyright 2003 J. Schilling */
#ifndef lint
static	char sccsid[] =
	"@(#)strdup.c	1.2 06/09/13 Copyright 2003 J. Schilling";
#endif
/*
 *	strdup() to be used if missing on libc
 *
 *	Copyright (c) 2003 J. Schilling
 */
/*
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * See the file CDDL.Schily.txt in this distribution for details.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file CDDL.Schily.txt from this distribution.
 */

#include <schily/mconfig.h>
#include <schily/standard.h>
#include <schily/stdlib.h>
#include <schily/string.h>
#include <schily/schily.h>
#include <schily/libport.h>

#ifndef	HAVE_STRDUP

EXPORT char *
strdup(s)
	const char	*s;
{
	unsigned i	= strlen(s) + 1;
	char	 *res	= malloc(i);

	if (res == NULL)
		return (NULL);
	if (i > 16) {
		movebytes(s, res, (int) i);
	} else {
		char	*s2 = res;

		while ((*s2++ = *s++) != '\0')
			;
	}
	return (res);
}
#endif	/* HAVE_STRDUP */

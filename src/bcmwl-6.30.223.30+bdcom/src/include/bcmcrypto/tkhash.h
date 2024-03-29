/*
 * tkhash.h
 * Prototypes for TKIP hash functions.
 *
 * Copyright (C) 2011, Broadcom Corporation. All Rights Reserved.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $Id: tkhash.h 326260 2012-04-06 20:38:09Z $
 */

#ifndef _TKHASH_H_
#define _TKHASH_H_

#include <typedefs.h>

#define TKHASH_P1_KEY_SIZE	10	
#define TKHASH_P2_KEY_SIZE	16	

extern void BCMROMFN(tkhash_phase1)(uint16 *P1K, const uint8 *TK, const uint8 *TA, uint32 IV32);
extern void BCMROMFN(tkhash_phase2)(uint8 *RC4KEY, const uint8 *TK, const uint16 *P1K, uint16 IV16);

#endif 

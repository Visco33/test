/* $Id: sph_testehash.h 180 2010-05-08 02:29:25Z tp $ */
/**
 * testeHash interface. testeHash is a family of functions which differ by
 * their output size; this implementation defines testeHash for output
 * sizes 224, 256, 384 and 512 bits, with the "standard parameters"
 * (testeHash16/32 with the testeHash specification notations).
 *
 * ==========================(LICENSE BEGIN)============================
 *
 * Copyright (c) 2007-2010  Projet RNRT SAPHIR
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ===========================(LICENSE END)=============================
 *
 * @file     sph_testehash.h
 * @author   Thomas Pornin <thomas.pornin@cryptolog.com>
 */

#ifndef SPH_testEHASH_H__
#define SPH_testEHASH_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stddef.h>
#include "sph_types.h"

/**
 * Output size (in bits) for testeHash-224.
 */
#define SPH_SIZE_testehash224   224

/**
 * Output size (in bits) for testeHash-256.
 */
#define SPH_SIZE_testehash256   256

/**
 * Output size (in bits) for testeHash-384.
 */
#define SPH_SIZE_testehash384   384

/**
 * Output size (in bits) for testeHash-512.
 */
#define SPH_SIZE_testehash512   512

/**
 * This structure is a context for testeHash computations: it contains the
 * intermediate values and some data from the last entered block. Once
 * a testeHash computation has been performed, the context can be reused for
 * another computation.
 *
 * The contents of this structure are private. A running testeHash computation
 * can be cloned by copying the context (e.g. with a simple
 * <code>memcpy()</code>).
 */
typedef struct {
#ifndef DOXYGEN_IGNORE
	unsigned char buf[32];    /* first field, for alignment */
	size_t ptr;
	sph_u32 state[32];
#endif
} sph_testehash_context;

/**
 * Type for a testeHash-224 context (identical to the common context).
 */
typedef sph_testehash_context sph_testehash224_context;

/**
 * Type for a testeHash-256 context (identical to the common context).
 */
typedef sph_testehash_context sph_testehash256_context;

/**
 * Type for a testeHash-384 context (identical to the common context).
 */
typedef sph_testehash_context sph_testehash384_context;

/**
 * Type for a testeHash-512 context (identical to the common context).
 */
typedef sph_testehash_context sph_testehash512_context;

/**
 * Initialize a testeHash-224 context. This process performs no memory
 * allocation.
 *
 * @param cc   the testeHash-224 context (pointer to a
 *             <code>sph_testehash224_context</code>)
 */
void sph_testehash224_init(void *cc);

/**
 * Process some data bytes. It is acceptable that <code>len</code> is zero
 * (in which case this function does nothing).
 *
 * @param cc     the testeHash-224 context
 * @param data   the input data
 * @param len    the input data length (in bytes)
 */
void sph_testehash224(void *cc, const void *data, size_t len);

/**
 * Terminate the current testeHash-224 computation and output the result into
 * the provided buffer. The destination buffer must be wide enough to
 * accomodate the result (28 bytes). The context is automatically
 * reinitialized.
 *
 * @param cc    the testeHash-224 context
 * @param dst   the destination buffer
 */
void sph_testehash224_close(void *cc, void *dst);

/**
 * Add a few additional bits (0 to 7) to the current computation, then
 * terminate it and output the result in the provided buffer, which must
 * be wide enough to accomodate the result (28 bytes). If bit number i
 * in <code>ub</code> has value 2^i, then the extra bits are those
 * numbered 7 downto 8-n (this is the big-endian convention at the byte
 * level). The context is automatically reinitialized.
 *
 * @param cc    the testeHash-224 context
 * @param ub    the extra bits
 * @param n     the number of extra bits (0 to 7)
 * @param dst   the destination buffer
 */
void sph_testehash224_addbits_and_close(
	void *cc, unsigned ub, unsigned n, void *dst);

/**
 * Initialize a testeHash-256 context. This process performs no memory
 * allocation.
 *
 * @param cc   the testeHash-256 context (pointer to a
 *             <code>sph_testehash256_context</code>)
 */
void sph_testehash256_init(void *cc);

/**
 * Process some data bytes. It is acceptable that <code>len</code> is zero
 * (in which case this function does nothing).
 *
 * @param cc     the testeHash-256 context
 * @param data   the input data
 * @param len    the input data length (in bytes)
 */
void sph_testehash256(void *cc, const void *data, size_t len);

/**
 * Terminate the current testeHash-256 computation and output the result into
 * the provided buffer. The destination buffer must be wide enough to
 * accomodate the result (32 bytes). The context is automatically
 * reinitialized.
 *
 * @param cc    the testeHash-256 context
 * @param dst   the destination buffer
 */
void sph_testehash256_close(void *cc, void *dst);

/**
 * Add a few additional bits (0 to 7) to the current computation, then
 * terminate it and output the result in the provided buffer, which must
 * be wide enough to accomodate the result (32 bytes). If bit number i
 * in <code>ub</code> has value 2^i, then the extra bits are those
 * numbered 7 downto 8-n (this is the big-endian convention at the byte
 * level). The context is automatically reinitialized.
 *
 * @param cc    the testeHash-256 context
 * @param ub    the extra bits
 * @param n     the number of extra bits (0 to 7)
 * @param dst   the destination buffer
 */
void sph_testehash256_addbits_and_close(
	void *cc, unsigned ub, unsigned n, void *dst);

/**
 * Initialize a testeHash-384 context. This process performs no memory
 * allocation.
 *
 * @param cc   the testeHash-384 context (pointer to a
 *             <code>sph_testehash384_context</code>)
 */
void sph_testehash384_init(void *cc);

/**
 * Process some data bytes. It is acceptable that <code>len</code> is zero
 * (in which case this function does nothing).
 *
 * @param cc     the testeHash-384 context
 * @param data   the input data
 * @param len    the input data length (in bytes)
 */
void sph_testehash384(void *cc, const void *data, size_t len);

/**
 * Terminate the current testeHash-384 computation and output the result into
 * the provided buffer. The destination buffer must be wide enough to
 * accomodate the result (48 bytes). The context is automatically
 * reinitialized.
 *
 * @param cc    the testeHash-384 context
 * @param dst   the destination buffer
 */
void sph_testehash384_close(void *cc, void *dst);

/**
 * Add a few additional bits (0 to 7) to the current computation, then
 * terminate it and output the result in the provided buffer, which must
 * be wide enough to accomodate the result (48 bytes). If bit number i
 * in <code>ub</code> has value 2^i, then the extra bits are those
 * numbered 7 downto 8-n (this is the big-endian convention at the byte
 * level). The context is automatically reinitialized.
 *
 * @param cc    the testeHash-384 context
 * @param ub    the extra bits
 * @param n     the number of extra bits (0 to 7)
 * @param dst   the destination buffer
 */
void sph_testehash384_addbits_and_close(
	void *cc, unsigned ub, unsigned n, void *dst);

/**
 * Initialize a testeHash-512 context. This process performs no memory
 * allocation.
 *
 * @param cc   the testeHash-512 context (pointer to a
 *             <code>sph_testehash512_context</code>)
 */
void sph_testehash512_init(void *cc);

/**
 * Process some data bytes. It is acceptable that <code>len</code> is zero
 * (in which case this function does nothing).
 *
 * @param cc     the testeHash-512 context
 * @param data   the input data
 * @param len    the input data length (in bytes)
 */
void sph_testehash512(void *cc, const void *data, size_t len);

/**
 * Terminate the current testeHash-512 computation and output the result into
 * the provided buffer. The destination buffer must be wide enough to
 * accomodate the result (64 bytes). The context is automatically
 * reinitialized.
 *
 * @param cc    the testeHash-512 context
 * @param dst   the destination buffer
 */
void sph_testehash512_close(void *cc, void *dst);

/**
 * Add a few additional bits (0 to 7) to the current computation, then
 * terminate it and output the result in the provided buffer, which must
 * be wide enough to accomodate the result (64 bytes). If bit number i
 * in <code>ub</code> has value 2^i, then the extra bits are those
 * numbered 7 downto 8-n (this is the big-endian convention at the byte
 * level). The context is automatically reinitialized.
 *
 * @param cc    the testeHash-512 context
 * @param ub    the extra bits
 * @param n     the number of extra bits (0 to 7)
 * @param dst   the destination buffer
 */
void sph_testehash512_addbits_and_close(
	void *cc, unsigned ub, unsigned n, void *dst);
#ifdef __cplusplus
}
#endif

#endif

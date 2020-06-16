#ifndef ZMForceAtmMsis2000_H

/* -------------------------------------------------------------------- */
/* ---------  N R L M S I S E - 0 0    M O D E L    2 0 0 1  ---------- */
/* -------------------------------------------------------------------- */

/* This file is part of the NRLMSISE-00  C source code package - release
 * 20041227
 *
 * The NRLMSISE-00 model was developed by Mike Picone, Alan Hedin, and
 * Doug Drob. They also wrote a NRLMSISE-00 distribution package in 
 * FORTRAN which is available at
 * http://uap-www.nrl.navy.mil/models_web/msis/msis_home.htm
 *
 * Dominik Brodowski implemented and maintains this C version. You can
 * reach him at mail@brodo.de. See the file "DOCUMENTATION" for details,
 * and check http://www.brodo.de/english/pub/nrlmsise/index.html for
 * updated releases of this package.
 */

/* ------------------------------------------------------------------- */
/* --------------------------- PROTOTYPES ---------------------------- */
/* ------------------------------------------------------------------- */

/* GTD7 */
/*   Neutral Atmosphere Empircial Model from the surface to lower
 *   exosphere.
 */
void gtd7 (struct nrlmsise_input *input, struct nrlmsise_flags *flags, struct nrlmsise_output *output);


/* GTD7D */
/*   This subroutine provides Effective Total Mass Density for output
 *   d[5] which includes contributions from "anomalous oxygen" which can
 *   affect satellite drag above 500 km. See the section "output" for
 *   additional details.
 */
void gtd7d(struct nrlmsise_input *input, \
           struct nrlmsise_flags *flags, \
           struct nrlmsise_output *output);


/* GTS7 */
/*   Thermospheric portion of NRLMSISE-00
 */
void gts7 (struct nrlmsise_input *input, \
	   struct nrlmsise_flags *flags, \
	   struct nrlmsise_output *output);


/* GHP7 */
/*   To specify outputs at a pressure level (press) rather than at
 *   an altitude.
 */
void ghp7 (struct nrlmsise_input *input, \
           struct nrlmsise_flags *flags, \
           struct nrlmsise_output *output, \
           double press);


/* ------------------------------------------------------------------- */
#endif // #ifndef ZMForceAtmMsis2000_H

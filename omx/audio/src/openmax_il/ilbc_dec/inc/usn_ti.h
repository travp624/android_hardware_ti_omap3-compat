
/*
 * Copyright (C) Texas Instruments - http://www.ti.com/
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
/* =============================================================================
*             Texas Instruments OMAP(TM) Platform Software
*  (c) Copyright Texas Instruments, Incorporated.  All Rights Reserved.
*
*  Use of this software is controlled by the terms and conditions found
*  in the license agreement under which this software has been supplied.
* ============================================================================ */
/**
* @file OMX_PcmDec_CompThread.h
*
* This is an header file for an audio PCM decoder that is fully
* compliant with the OMX Audio specification.
* This the file is used internally by the component
* in its code and it contains UUIDs of USN and DCTN used by the component.
*
* @path  $(CSLPATH)\OMAPSW_MPU\linux\audio\src\openmax_il\pcm_dec\inc\
*
* @rev 1.0
*/
/* --------------------------------------------------------------------------- */

#ifndef USN_TI_H
#define USN_TI_H

/* ======================================================================= */
/** USN_TI_UUID: This struct contains the UUID is USN on DSP.
*/
/* ==================================================================== */
struct DSP_UUID USN_TI_UUID = {
   0x79A3C8B3, 0x95F2, 0x403F, 0x9A, 0x4B, {
   0xCF, 0x80, 0x57, 0x73, 0x05, 0x41
   }
};

/* ======================================================================= */
/** DCTN_TI_UUID: This struct contains the UUID is DCTN on DSP.
*/
/* ==================================================================== */
struct DSP_UUID DCTN_TI_UUID = {
	0xa62dc01d, 0x0c11, 0x4bdc, 0xaa, 0xf5, {
	0xa9, 0xda, 0x67, 0x45, 0x99, 0x6e
    }
};
#endif /* USN_TI_H */



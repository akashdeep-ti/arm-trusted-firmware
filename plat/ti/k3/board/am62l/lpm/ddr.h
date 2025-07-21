/*
 * Copyright (c) 2024-2025, Texas Instruments Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __LPM_DDR_H__
#define __LPM_DDR_H__

#include <plat/common/platform.h>

/**
 *  \brief  Put DDR in self refresh for rtc only mode
 *
 *  \return ret SUCCESS on success
 */
__wkupsramfunc int32_t put_ddr_in_rtc_lpm(void);

/**
 *  \brief  Put ddr in self refresh
 *
 * @param enable bool to chose between enable and disable
 *
 *  \return ret SUCCESS on success
 */
__wkupsramfunc void put_ddr_in_sr(bool enable);

/**
 *  \brief  Restore DDR register configs
 *
 *  \return ret SUCCESS on success
 */
__wkupsramfunc int32_t restore_ddr_reg_configs(void);

/**
 *  \brief  Save DDR register configs
 *
 *  \return ret SUCCESS on success
 */
__wkupsramfunc int32_t save_ddr_reg_configs(void);

/**
 * \brief Execute DDR Frequency Set Point (FSP) change sequence
 *
 * This function performs a complete hardware handshake sequence to change the
 * DDR operating frequency by switching to a different FSP. The sequence involves
 * coordinating between the DDR controller, PLL, and WKUP control registers.
 *
 * \param fsp_point Target FSP to switch to (0, 1, or 2)
 *
 * \return 0 on success, negative error code on failure:
 *         -1: Timeout waiting for controller busy to clear
 *         -2: Timeout waiting for FSP clock change request
 *         -3: Invalid FSP request type
 *         -4: Timeout waiting for clock change request to clear
 *         -5: Timeout waiting for DDR FSP acknowledgment
 *         -6: DDR FSP acknowledgment error bit set
 *         -7: Timeout waiting for DFS interrupt status
 *         -8: DFS operation error (HW/SW ignored or timeout)
 */
__wkupsramfunc int32_t execute_ddr_fsp_seq(uint8_t fsp_point);

#endif /* __LPM_DDR_H__ */

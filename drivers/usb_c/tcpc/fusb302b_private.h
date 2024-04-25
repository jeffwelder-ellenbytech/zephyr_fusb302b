/*
 * Copyright 2023 Jonas Otto
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_USBC_DEVICE_FUSB302B_PRIVATE_H_
#define ZEPHYR_DRIVERS_USBC_DEVICE_FUSB302B_PRIVATE_H_

#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/usb_c/usbc_tcpc.h>

#define FUSB302_RX_BUFFER_SIZE 80

struct alert_info {
  void *data;
  tcpc_alert_handler_cb_t handler;
};

struct fusb302b_data {
  struct alert_info alert_info;
  int cc;
};

struct fusb302b_cfg {
  struct i2c_dt_spec i2c;
};

enum cc_res { CC_RES_1, CC_RES_2, CC_RES_BOTH, CC_RES_NONE };

int fusb302b_init(const struct device *dev);
int fusb302b_get_cc_line_source(const struct fusb302b_cfg *cfg,
                                enum cc_res *out);

#endif /* ZEPHYR_DRIVERS_USBC_DEVICE_FUSB302B_PRIVATE_H_ */

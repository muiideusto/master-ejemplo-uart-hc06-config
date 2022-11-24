/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

static UnbufferedSerial serial_port_hc06(PA_0, PA_1, 9600);
static UnbufferedSerial serial_port_usb(USBTX, USBRX, 9600);

char datoRx[1];

int main() {
  serial_port_hc06.set_blocking(false);
  serial_port_usb.set_blocking(false);

  while (true) {

    if (serial_port_hc06.readable() == true) {
      serial_port_hc06.read(&datoRx, 1);
      serial_port_usb.write(&datoRx, 1);
    }
    if (serial_port_usb.readable() == true) {
      serial_port_usb.read(&datoRx, 1);
      serial_port_hc06.write(&datoRx, 1);
    }

    wait_us(1000);
  }
}

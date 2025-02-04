/*
  TwoWire.h - TWI/I2C library for Arduino & Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/

#ifndef TwoWire_h
#define TwoWire_h

#include <inttypes.h>
// #include "Stream.h"
#include "api/HardwareI2C.h"
#include "Wire_IICA.h"

#define I2C_SLAVE_MODE_UNSUPPORTED

#define BUFFER_LENGTH 32

namespace arduino {

class TwoWire : public HardwareI2C
{
  private:
    uint8_t channel;

    IICA_Impl iica;

    uint8_t rxBuffer[BUFFER_LENGTH];
    uint8_t rxBufferIndex;
    uint8_t rxBufferLength;

    uint8_t txAddress;
    uint8_t txBuffer[BUFFER_LENGTH];
    uint8_t txBufferIndex;
    uint8_t txBufferLength;

    uint8_t transmitting;
    void (*user_onRequest)(void);
    void (*user_onReceive)(int);
    void onRequestService(void);
    void onReceiveService(uint8_t*, int);

    void initializeProps(void);

  public:
    TwoWire(uint8_t ch = 0);

    void begin() override;
    void end() override;
#if !defined(I2C_SLAVE_MODE_UNSUPPORTED)
    void begin(uint8_t);
    void begin(int);
#endif  /* !defined(I2C_SLAVE_MODE_UNSUPPORTED) */

    void begin(uint8_t) override;

    void setClock(uint32_t) override;
    void beginTransmission(uint8_t) override;
//    void beginTransmission(int);
    uint8_t endTransmission(void) override;
    uint8_t endTransmission(bool) override;
    size_t requestFrom(uint8_t, size_t) override;
    size_t requestFrom(uint8_t, size_t, bool) override;
//    size_t requestFrom(int, int);
//    size_t requestFrom(int, int, int);
    virtual size_t write(uint8_t) override;
    virtual size_t write(const uint8_t *, size_t) override;
    virtual int available(void) override;
    virtual int read(void) override;
    virtual int peek(void) override;
    virtual void flush(void) override;
    void onReceive( void (*)(int) ) override;
    void onRequest( void (*)(void) ) override;

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

    virtual int availableForWrite() override;
};

}

#if     defined(IIC_CHANNEL0) && IIC_CHANNEL0 == 0
extern arduino::TwoWire Wire;
#endif  /* defined(IIC_CHANNEL0) && IIC_CHANNEL0 == 0 */

#if     defined(IIC_CHANNEL1) && IIC_CHANNEL1 == 1
extern arduino::TwoWire Wire4;
#endif  /* defined(IIC_CHANNEL1) && IIC_CHANNEL1 == 1 */

#if     defined(IIC_CHANNEL2) && IIC_CHANNEL2 == 2
extern arduino::TwoWire Wire1;
#endif  /* defined(IIC_CHANNEL2) && IIC_CHANNEL2 == 2 */

#if     defined(IIC_CHANNEL3) && IIC_CHANNEL3 == 3
extern arduino::TwoWire Wire2;
#endif  /* defined(IIC_CHANNEL3) && IIC_CHANNEL3 == 3 */

#if     defined(IIC_CHANNEL4) && IIC_CHANNEL4 == 4
extern arduino::TwoWire Wire3;
#endif  /* defined(IIC_CHANNEL4) && IIC_CHANNEL4 == 4 */

#endif /* TwoWire_h */


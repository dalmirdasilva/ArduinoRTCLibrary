/**
 * Arduino - Real Time Clock
 *
 * Implementation for DS1307.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_REAL_TIME_CLOCK_DS1307_H__
#define __ARDUINO_REAL_TIME_CLOCK_DS1307_H__ 1

#include <RealTimeClock.h>
#include <RegisterBasedWiredDevice.h>

#define DS1307_ADDRESS  0xd0

/**
 * <pre>
 * +---------+------+------+------+------+------+------+------+------+----------+-------+
 * |ADDRESS  | BIT7 | BIT6 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0 | FUNCTION | RANGE |
 * +---------+------+------+------+------+------+------+------+------+----------+-------+
 * | 00h     | CH   | 10 Seconds         | Seconds                   | Seconds  | 00-59 |
 * +---------+------+--------------------+---------------------------+----------+-------+
 * | 01h     | 0    | 10 Minutes         | Minutes                   | Minutes  | 00-59 |
 * +---------+------+------+------+------+---------------------------+----------+-------+
 * | 02h     | 0    | 1:12 | 10 H | 10   | Hours                     | Hours    | 1–12  |
 * |         |      | 0:24 | PM/AM| Hour |                           |          | AM/PM |
 * |         |      |      |      |      |                           |          | 00–23 |
 * +---------+------+------+------+------+------+--------------------+----------+-------+
 * | 03h     | 0    | 0    | 0    | 0    | 0    | Day                | Day      | 01-07 |
 * +---------+------+------+------+------+------+--------------------+----------+-------+
 * | 04h     | 0    | 0    | 10 Date     | Date                      | Date     | 01-31 |
 * +---------+------+------+------+------+---------------------------+----------+-------+
 * | 05h     | 0    | 0    | 0    | 10Mo | Month                     | Month    | 01-12 |
 * +---------+------+------+------+------+---------------------------+----------+-------+
 * | 06h     | 10 Year                   | Year                      | Year     | 00–99 |
 * +---------+------+------+------+------+------+------+------+------+----------+-------+
 * | 07h     | OUT  | 0    | 0    | SQWE | 0    | 0    | RS1  | RS0  | Control  | —     |
 * +---------+------+------+------+------+------+------+------+------+----------+-------+
 * | 08h–3Fh |                                                       | RAM 56x8 | 00–FF |
 * +---------+------------------------------------------------------------------+-------+
 */
class RealTimeClockDS1307: public RealTimeClock, public RegisterBasedWiredDevice {

public:

    /**
     * Registers
     */
    enum Register {
        SECONDS_REGISTER = 0x00,
        MINUTES_REGISTER = 0x01,
        HOURS_REGISTER = 0x02,
        DAY_REGISTER = 0x03,
        DATE_REGISTER = 0x04,
        MONTH_REGISTER = 0x05,
        YEAR_REGISTER = 0x06,
        CONTROL_REGISTER = 0x07
    };

    enum Mask {
        CONTROL_OUT = 0x80,
        CONTROL_SQWE = 0x10,
        CONTROL_RS1 = 0x02,
        CONTROL_RS2 = 0x01,
    };

    struct SecondsBits {

        struct {
            unsigned char SECONDS :4;
            unsigned char TEN_SECONDS :3;
            unsigned char CH :1;
        };
        unsigned char value;
    };

    struct MinutesBits {

        struct {
            unsigned char MINUTES :4;
            unsigned char TEN_MINUTES :3;
            unsigned char :1;
        };
        unsigned char value;
    };

    struct HourBits {

        struct {
            unsigned char HOURS :4;
            unsigned char PM_AM :1;
            unsigned char MODE_12_24 :1;
            unsigned char :1;
        };

        struct {
            unsigned char :4;
            unsigned char TEM_HOURS :2;
            unsigned char : 2;
        };
        unsigned char value;
    };

    struct DayBits {

        struct {
            unsigned char DAY :3;
            unsigned char :5;
        };
        unsigned char value;
    };

    struct DateBits {

        struct {
            unsigned char DATE :4;
            unsigned char TEN_DATE :2;
            unsigned char :2;
        };
        unsigned char value;
    };

    struct MonthBits {

        struct {
            unsigned char MONTH :4;
            unsigned char TEN_MONTH :1;
            unsigned char :3;
        };
        unsigned char value;
    };

    struct YearBits {

        struct {
            unsigned char YEAR :4;
            unsigned char TEN_YEAR:4;
        };
        unsigned char value;
    };

    /**
     * The DS1307 control register is used to control the operation of the SQW/OUT pin.
     *
     * BIT7 BIT6 BIT5 BIT4 BIT3 BIT2 BIT1 BIT0
     * OUT  0    0    SQWE 0    0    RS1  RS0
     *
     * Bit 7: Output Control (OUT). This bit controls the output level of the SQW/OUT pin when the square-wave output
     * is disabled. If SQWE = 0, the logic level on the SQW/OUT pin is 1 if OUT = 1 and is 0 if OUT = 0. On initial
     * application of power to the device, this bit is typically set to a 0.
     *
     * Bit 4: Square-Wave Enable (SQWE). This bit, when set to logic 1, enables the oscillator output. The frequency of
     * the square-wave output depends upon the value of the RS0 and RS1 bits. With the square-wave output set to 1Hz,
     * the clock registers update on the falling edge of the square wave. On initial application of power to the device, this
     * bit is typically set to a 0.
     *
     * Bits 1 and 0: Rate Select (RS[1:0]). These bits control the frequency of the square-wave output when the squarewave
     * output has been enabled. The following table lists the square-wave frequencies that can be selected with the
     * RS bits. On initial application of power to the device, these bits are typically set to a 1.
     *
     * RS1 RS0 SQW/OUT OUTPUT SQWE OUT
     * 0 0 1Hz 1 X
     * 0 1 4.096kHz 1 X
     * 1 0 8.192kHz 1 X
     * 1 1 32.768kHz 1 X
     * X X 0 0 0
     * X X 1 0 1
     */
    struct ControlBits {

        struct {
            unsigned char RS0 :1;
            unsigned char RS1 :1;
            unsigned char :2;
            unsigned char SQWE :1;
            unsigned char :2;
            unsigned char OUT :1;
        };
        struct {
            unsigned char RS :2;
            unsigned char :6;
        };
        unsigned char value;
    };

    RealTimeClockDS1307();

    /**
     * Return the current seconds.
     */
    unsigned char getSeconds();

    /**
     * Return the current minutes.
     */
    unsigned char getMinutes();

    /**
     * Return the current hour.
     */
    unsigned char getHour();

    /**
     * Return the current day.
     */
    unsigned char getDay();

    /**
     * Return the current date.
     */
    unsigned char getDate();

    /**
     * Return the current month.
     */
    unsigned char getMonth();

    /**
     * Return the current year.
     */
    unsigned char getYear();
};

#endif /* __ARDUINO_REAL_TIME_CLOCK_DS1307_H__ */

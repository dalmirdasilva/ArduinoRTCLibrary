/**
 * Arduino - Real Time Clock
 *
 * Interface for real time clocks.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_REAL_TIME_CLOCK_H__
#define __ARDUINO_REAL_TIME_CLOCK_H__ 1

class RealTimeClock {

public:

    virtual ~RealTimeClock();

    /**
     * Return the current seconds.
     */
    virtual unsigned char getSeconds() = 0;

    /**
     * Return the current minutes.
     */
    virtual unsigned char getMinutes() = 0;

    /**
     * Return the current hour.
     */
    virtual unsigned char getHour() = 0;

    /**
     * Return the current day.
     */
    virtual unsigned char getDay() = 0;

    /**
     * Return the current date.
     */
    virtual unsigned char getDate() = 0;

    /**
     * Return the current month.
     */
    virtual unsigned char getMonth() = 0;

    /**
     * Return the current year.
     */
    virtual unsigned char getYear() = 0;

    /**
     * PM/AP
     */
    virtual bool isPM() = 0;
};

#endif /* __ARDUINO_REAL_TIME_CLOCK_H__ */

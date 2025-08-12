/*
 *
 *      tty.h
 *      Teletype header file
 *
 *      2025/4/12 By MicroFish
 *      Based on GPL-3.0 open source agreement
 *      Copyright © 2020 ViudiraTech, based on the GPLv3 agreement.
 *
 */

#ifndef INCLUDE_TTY_H_
#define INCLUDE_TTY_H_

#define MAX_ARGC    1024
#define MAX_CMDLINE 256

#ifndef TTY_BUF_SIZE
#    define TTY_BUF_SIZE 4096
#endif

#ifndef TTY_DEFAULT_DEV
#    define TTY_DEFAULT_DEV "tty0"
#endif

/* Obtain the tty number provided at startup */
char *get_boot_tty(void);

/* Print characters to tty */
void tty_print_ch(const char ch);

/* Print string to tty */
void tty_print_str(const char *str);

/* Flush tty buffer */
void tty_buff_flush(void);

#endif // INCLUDE_TTY_H_

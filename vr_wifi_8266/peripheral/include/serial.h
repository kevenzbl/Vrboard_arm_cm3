#ifndef __SERIAL_H__
#define __SERIAL_H__

void serPutc(char c);
void serPuts(const char *s);
char serGetc(void);
void serInit(void);
void dbg_printf(char *fmt, ...);



#endif

#ifndef DISPLAYDRIVER_H
#define	DISPLAYDRIVER_H

void init_LCD (void);
void lcd_on_off (unsigned char enable);//sleep
void LCDinverse (unsigned char enable);
void LCDsoftreset (void);
void LCDshutdown (void);
void refresh_display (void);
void refresh_changed (void);
void paint_splash(void);

#endif	/* DISPLAYDRIVER_H */


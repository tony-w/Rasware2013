#ifndef _LED_H_
#define _LED_H_

#define RED 0
#define GREEN 1
#define BLUE 2
#define OFF 3

/**
 * Toggles LED between Green and Blue
 */
void toggleLed(int* currColor);

/**
* Sets the LED to either RED, GREEN, BLUE, or OFF.
*/
void setLed(int color);

#endif

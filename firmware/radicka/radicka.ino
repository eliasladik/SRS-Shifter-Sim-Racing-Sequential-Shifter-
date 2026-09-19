/*
 * radicka.ino
 * -----------
 * Firmware pro vlastní sekvenční řadičku pro sim racing.
 *
 * HW:  Arduino Pro Micro / Leonardo (ATmega32U4 - nativní USB HID)
 * Vstup: 2x mikrospínač (nahoru / dolů), zapojený mezi pin a GND
 * Výstup: USB gamepad se 2 tlačítky (žádné osy)
 *
 * Potřebné knihovny (Arduino IDE -> Library Manager):
 *   - "Joystick" od Matthew Heironimus
 *     https://github.com/MHeironimus/ArduinoJoystickLibrary
 *   - "Bounce2" od Thomas Fredericks
 *
 * Nastavení desky v Arduino IDE:
 *   Tools -> Board -> Arduino Leonardo (nebo Pro Micro dle bootloaderu)
 */

#include <Joystick.h>
#include <Bounce2.h>

// ---------------------------------------------------------------------
// Konfigurace pinů - uprav podle svého zapojení
// ---------------------------------------------------------------------
const uint8_t PIN_SHIFT_UP   = 2;   // mikrospínač "nahoru" -> druhý kontakt na GND
const uint8_t PIN_SHIFT_DOWN = 3;   // mikrospínač "dolů"   -> druhý kontakt na GND

const unsigned long DEBOUNCE_MS = 8; // doba debounce v ms, klidně dolaď

// ---------------------------------------------------------------------
// Definice joysticku - jen 2 tlačítka, žádné osy/hat switche
// ---------------------------------------------------------------------
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_GAMEPAD,
  2,      // počet tlačítek
  0,      // počet hat switchů
  false, false, false,   // X, Y, Z osa
  false, false, false,   // Rx, Ry, Rz
  false,  // rudder
  false,  // throttle
  false,  // accelerator
  false,  // brake
  false   // steering
);

const uint8_t BTN_SHIFT_UP   = 0;
const uint8_t BTN_SHIFT_DOWN = 1;

Bounce debUp   = Bounce();
Bounce debDown = Bounce();

void setup() {
  pinMode(PIN_SHIFT_UP, INPUT_PULLUP);
  pinMode(PIN_SHIFT_DOWN, INPUT_PULLUP);

  debUp.attach(PIN_SHIFT_UP);
  debUp.interval(DEBOUNCE_MS);

  debDown.attach(PIN_SHIFT_DOWN);
  debDown.interval(DEBOUNCE_MS);

  Joystick.begin();
}

void loop() {
  debUp.update();
  debDown.update();

  // spínače jsou zapojené proti GND (INPUT_PULLUP) -> sepnuto = LOW
  Joystick.setButton(BTN_SHIFT_UP,   debUp.read()   == LOW);
  Joystick.setButton(BTN_SHIFT_DOWN, debDown.read() == LOW);
}

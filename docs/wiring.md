# Zapojení

## Komponenty
- Arduino Pro Micro (ATmega32U4)
- 2x mikrospínač (nahoru / dolů)

## Schéma zapojení (jednoduché, bez rezistorů)

Oba mikrospínače se zapojují mezi příslušný pin a GND. Vnitřní pull-up
rezistory jsou zapnuté v kódu (`INPUT_PULLUP`), takže žádné externí
rezistory nejsou potřeba.

```
Pro Micro PIN 2  ----[mikrospínač NAHORU]---- GND
Pro Micro PIN 3  ----[mikrospínač DOLŮ]------ GND
```

- V klidu (nesepnuto) čte pin HIGH.
- Při sepnutí spínače se pin připojí na GND -> čte LOW.

## Změna pinů

Pokud chceš spínače zapojit na jiné piny, uprav v `firmware/radicka/radicka.ino`:

```cpp
const uint8_t PIN_SHIFT_UP   = 2;
const uint8_t PIN_SHIFT_DOWN = 3;
```

Piny 0 a 1 na Pro Micro jsou RX/TX (UART) - těm se vyhni, pokud
zároveň neřešíš sériovou komunikaci.

## Debounce

Mikrospínače mají mechanický zákmit v řádu jednotek ms. V kódu je
nastaven softwarový debounce (knihovna Bounce2, `DEBOUNCE_MS`).
Pokud by hra hlásila "vícenásobné" řazení, zkus tuto hodnotu zvýšit
(např. na 15-20 ms).

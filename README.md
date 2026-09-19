# Radička

Vlastní sekvenční řadička pro sim racing, postavená na Arduino Pro Micro.
Do PC/hry se hlásí jako USB gamepad se 2 tlačítky (nahoru / dolů).

## Hardware
- Arduino Pro Micro (ATmega32U4)
- 2x mikrospínač (nahoru / dolů)

Zapojení viz [`docs/wiring.md`](docs/wiring.md).

## Struktura projektu

```
radicka/
├── firmware/
│   └── radicka/
│       └── radicka.ino     # hlavní firmware
├── docs/
│   └── wiring.md            # schéma zapojení
├── dily/                    # 3D modely, výkresy, datasheety
├── bom/
│   └── BOM.md                # kusovník
├── obrazky/                  # fotky, screenshoty
└── README.md
```

## Potřebné knihovny

V Arduino IDE přes Library Manager (Sketch -> Include Library -> Manage Libraries):
- **Joystick** – Matthew Heironimus – https://github.com/MHeironimus/ArduinoJoystickLibrary
- **Bounce2** – Thomas Fredericks

## Nahrání firmwaru

1. Otevři `firmware/radicka/radicka.ino` v Arduino IDE.
2. Tools -> Board -> zvol desku odpovídající tvému Pro Micro/Leonardo bootloaderu.
3. Vyber správný port a nahraj (Upload).
4. Po nahrání se zařízení v systému objeví jako herní gamepad se 2 tlačítky.

## Otestování

- Windows: `joy.cpl` (Ovládání herních zařízení).
- Nebo přímo v nastavení ovladače ve hře přiřaď tlačítko 0 = řazení
  nahoru, tlačítko 1 = řazení dolů.

## Možná rozšíření do budoucna

- Přidání dalších tlačítek (handbrake, clutch bite point apod.)
- LED/OLED displej s aktuálním stupněm (řadička si stupeň sama
  nepamatuje, to řeší hra/sim)
- Vlastní 3D tištěné/kovové tělo řadičky

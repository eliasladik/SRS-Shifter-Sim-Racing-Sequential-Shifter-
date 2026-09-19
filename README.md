# 🏎️ Sim Racing Radička (Sekvenční)

> 🚧 **Upozornění:** Tento projekt je aktuálně ve vývoji (Work in Progress). Funkcionalita, dokumentace i modely se mohou v průběhu času měnit a vylepšovat!

Vlastní sekvenční řadička pro sim racing, postavená na mikrokontroléru **Arduino Pro Micro**. 
Do PC (nebo konkrétní hry) se hlásí jako standardní USB gamepad se 2 tlačítky (nahoru / dolů), díky čemuž funguje okamžitě a bez nutnosti instalace dalších ovladačů (Plug & Play).

---

## 🛠️ Hardware

- **Mikrokontrolér:** Arduino Pro Micro (ATmega32U4)
- **Spínače:** 2x mikrospínač (pro řazení nahoru a dolů)

📝 *Kompletní schéma zapojení najdete v souboru [`docs/wiring.md`](docs/wiring.md).*

## 📁 Struktura projektu

```text
radicka/
├── firmware/
│   └── radicka/
│       └── radicka.ino     # Hlavní zdrojový kód (firmware)
├── docs/
│   └── wiring.md           # Schéma zapojení a instrukce
├── dily/                   # 3D modely k tisku, výkresy, datasheety
├── bom/
│   └── BOM.md              # Kusovník (seznam materiálu)
├── obrazky/                # Fotogalerie, ukázky ze stavby a screenshoty
└── README.md               # Tento soubor
```

## 📚 Potřebné knihovny

Před kompilací firmwaru si v **Arduino IDE** přes Library Manager (*Sketch -> Include Library -> Manage Libraries*) nainstalujte následující knihovny:

- 🕹️ **Joystick** (od *Matthew Heironimus*) – [odkaz na GitHub](https://github.com/MHeironimus/ArduinoJoystickLibrary)
- 🔄 **Bounce2** (od *Thomas Fredericks*) – pro softwarové ošetření zákmitů tlačítek (debouncing)

## 🚀 Nahrání firmwaru

1. Otevřete soubor `firmware/radicka/radicka.ino` v Arduino IDE.
2. V horním menu přejděte na **Tools -> Board** a zvolte desku odpovídající vašemu modulu (typicky *Arduino Leonardo* nebo specifické *Pro Micro*).
3. Zvolte správný port (**Tools -> Port**).
4. Klikněte na tlačítko **Upload** (Nahrát).
5. Po úspěšném nahrání se zařízení v systému okamžitě objeví jako herní USB gamepad.

## 🎮 Otestování

- **Ve Windows:** Stiskněte `Win + R`, napište `joy.cpl` (Ovládání herních zařízení) a vyzkoušejte funkčnost stisknutím tlačítek na řadičce.
- **Ve hře:** Přímo v nastavení ovládání vašeho simulátoru přiřaďte:
  - Tlačítko 0 = Řazení nahoru (Shift Up)
  - Tlačítko 1 = Řazení dolů (Shift Down)

## 🔮 Možná rozšíření do budoucna

- [ ] Přidání dalších tlačítek (ruční brzda, spojka / bite point, navigace v menu).
- [ ] Integrace LED/OLED displeje zobrazujícího aktuální rychlostní stupeň *(Pozn.: Řadička si stupeň sama nepamatuje, bylo by nutné řešit obousměrnou komunikaci se hrou, např. přes SimHub).*
- [ ] Vlastní robustní 3D tištěné nebo kovové tělo řadičky pro reálnější odezvu.
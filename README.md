[![ShellCheck](https://github.com/biocoderh/keyboards/actions/workflows/shellcheck.yml/badge.svg)](https://github.com/biocoderh/keyboards/actions/workflows/shellcheck.yml)

# Keyboards

QMK keyboards

 - [Keymap](https://github.com/biocoderh/keyboards/tree/master/keymap)
 - [Layouts](https://github.com/biocoderh/keyboards/tree/master/layouts)
 - [Scylla](https://github.com/biocoderh/keyboards/tree/master/scylla)

# Usage

Before use make sure QMK is installed. [QMK Setup guide.](https://docs.qmk.fm/#/newbs_getting_started)

Use **./keyboards** script or simply copy needed keyboard folder to **qmk_firmware/keyboards/biocoderh/**

```console
Usage: keyboards [<command>] [<keyboard>] [<keymap>]

Commands:
    update              update git submodules (qmk_firmware, vial-qmk)

    lint <keyboard> [<keymap>]                          lint specified firmware
    compile <keyboard> [<keymap>]                       compile specified firmware
    flash <keyboard> [<keymap>] [--left|--right]        flash specified firmware, eeprom left/right available (only for 'caterina', 'atmel-dfu')

VIAL Specific:
    vial-lint <keyboard>                                lint specified firmware
    vial-compile <keyboard>                             compile specified firmware
    vial-flash <keyboard> [--left|--right]              flash specified firmware, eeprom left/right available (only for 'caterina', 'atmel-dfu')
```

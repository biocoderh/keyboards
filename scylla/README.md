[![Scylla lint](https://github.com/biocoderh/keyboards/actions/workflows/scylla-lint.yml/badge.svg)](https://github.com/biocoderh/keyboards/actions/workflows/scylla-lint.yml)

# Scylla

[Scylla](https://github.com/Bastardkb/Scylla) case with pro micro

[VIA](https://usevia.app/) keymap supported:
```console
./keyboards flash scylla via
```


## Flash

Use **./keyboards** scripts:
```console
./keyboards flash scylla default
```

Or alternativley copy **scylla** folder to **qmk_firmware/biocoderh/scylla** and use qmk directly:
```console
qmk flash -kb biocoderh/scylla -km default -bl avrdude-split-left
qmk flash -kb biocoderh/scylla -km default -bl avrdude-split-right
```

### Wiring
![image](images/wiring.svg)

### Matrix
![image](images/matrix.png)


## Troubleshooting

### Debounce

If you have issues with constant key repeats adjust [debounce](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_debounce_type.md) in **config.h**:

```c
#define DEBOUNCE 0 // default: 5
```

**rules.mk**:

```makefile
DEBOUNCE_TYPE = sym_eager_pk # default: sym_defer_g
```

### Serial speed

If you have issues with split features try to lower baud rate by increasing following value in **config.h**:

```c
#define SELECT_SOFT_SERIAL_SPEED 0 // default: 1
```

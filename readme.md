# ErgoA

```sh
git clone https://github.com/qmk/qmk_firmware
cd qmk_firmware
```

Building the ErgoA layout:

```sh
mkdir ./keyboards/ergodox/keymaps/ergoa
ln ~/Projects/ergoa/keymap.c keyboards/ergodox/keymaps/ergoa/keymap.c
docker run \
  -e keymap=ergoa \
  -e keyboard=ergodox \
  --rm -v $(pwd):/qmk:rw edasque/qmk_firmware
open ./.build
```


Building the experimental layout:

```sh
mkdir./keyboards/ergodox/keymaps/ergoa-exp
ln ~/Projects/ergoa/experimental.c keyboards/ergodox/keymaps/ergoa-exp/keymap.c
docker run \
  -e keymap=ergoa-exp \
  -e keyboard=ergodox \
  --rm -v $(pwd):/qmk:rw edasque/qmk_firmware
open ./.build
```

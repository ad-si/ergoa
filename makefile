# Build firmwares from available keymaps
.PHONY: all
all: build-default build-experimental


# Build the default ErgoA layout
build-%: qmk_firmware_copy_%/keyboards/ergodox_ez/keymaps/ergoa/keymap.c
	docker run \
		--env keyboard=ergodox_ez \
		--env subproject='' \
		--env keymap=ergoa \
		--rm \
		--volume $$(pwd)/qmk_firmware_copy_$*:/qmk:rw \
		edasque/qmk_firmware
	cp -r qmk_firmware_copy_$*/.build $@


# Copy keymap file to QMK repo
qmk_firmware_copy_%/keyboards/ergodox_ez/keymaps/ergoa/keymap.c: \
  %.c qmk_firmware_copy_%
	mkdir -p $(@D)
	cp $< $@


# Duplicate to avoid builds interfering with each other
qmk_firmware_copy_%: qmk_firmware
	cp -r $< $@


# Clone the QMK firmware repo to be able to build the ErgoDox EZ firmware
qmk_firmware:
	git clone \
		--depth 1 \
		--branch 0.5.130 \
		https://github.com/qmk/qmk_firmware


# Remove build artifacts
.PHONY:clean
clean:
	-rm -r build-*
	-rm -rf qmk_firmware*

# wulkan

Handwired 40% keyboard build with Proton C.

Keyboard Maintainer: [Napoleon Wulkan](https://github.com/wulkan)  
Hardware Supported: Proton C  
Hardware Availability: [OLKB.com](https://olkb.com)


Make example for this keyboard (after setting up your build environment):

    make handwired/wulkan:default:dfu-util

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


## Ofek

### Tutorial
https://beta.docs.qmk.fm/using-qmk/guides/keyboard-building/hand_wire#common-microcontroller-boards
I ignored everything after and including the step "Getting Some Basic Firmware Set Up" and used the next system setup guide in this readme instead
Connecting to the MCU using this https://www.reddit.com/r/olkb/comments/gktjal/i_need_help_with_understanding_what_each_pin_on/
Avoided B7, B6 and B5 (found this in some post in Reddit, not sure it is a must to follow this, though)
Another guide for handwiring plack using Proton C - https://www.rearvuemirror.com/guides/simple-hand-wired-40-keyboard

### Setup system for compilation
Follow the setup steps here:
https://beta.docs.qmk.fm/tutorial/newbs_getting_started
It has a small section on forking but I have not tested it, I simply forked on GitHub
then I just followed the next compile section below

### To compile:
1. open MinGW64
1. `PATH=$PATH:/C/Users/ofekp/.local/bin`
1. `cd /D/QMK/qmk_firmware`
1. Only after fist clone - `make git-submodule`
1. `qmk compile -kb handwired/wulkan -km default`

### To flash
first need STM32 drivers, follow this:
https://www.reddit.com/r/olkb/comments/a9gf47/guide_flashing_planck_rev6_or_stm32_pcb_on_windows/
It is ok to instll https://zadig.akeo.ie/ as the reddit post requires
Now the bin file from the compilation step can be flashed using 'QMK Toolbox'

### QMK key codes
https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes_basic

### Dynamic Macros
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dynamic_macros.md
Note the enabke flag in rules.mk

### Adding a gaming layer
https://www.reddit.com/r/olkb/comments/4vs4lo/how_do_i_add_a_gaming_layer/
https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions

### Unicode
https://docs.qmk.fm/#/feature_unicode?id=input-modes
https://beta.docs.qmk.fm/using-qmk/software-features/feature_unicode
for windows use UC_WINC which requires installing [WinCompose](https://github.com/samhocevar/wincompose)
https://www.compart.com/en/unicode/block/U+0370

### Combos
https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo

### Issues
I had to add `NO_USB_STARTUP_CHECK = yes` to rules.mk otherwise the keeb was unresposive after OS boot

### TODO
1. CMD + right arrow, CMD + left arrow = up, home
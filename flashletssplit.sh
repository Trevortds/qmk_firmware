make lets_split:trevor
cp .build/lets_split_rev2_trevor.hex keyboards/lets_split/keymaps/trevor/
avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:lets_split_rev2_trevor.hex

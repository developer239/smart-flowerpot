run: upload monitor

upload:
	pio -c clion run --target upload -e d1

monitor:
	pio -c clion device monitor -e d1

test:
	pio test -e d1 --verbose

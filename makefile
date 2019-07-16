led_key.bin:ctr0.S led_key.c
	arm-linux-gcc -g -c -o ctr0.o ctr0.S
	 arm-linux-gcc -g -c -o led_key.o led_key.c
	arm-linux-ld -Ttext 0x0000000 -g ctr0.o led_key.o -o led_key_elf
	arm-linux-objcopy -O binary -S led_key_elf led_key.bin
clean:
	rm -f led_key.bin led_key_elf *.o


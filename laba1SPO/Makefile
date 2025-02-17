CC = g++
CFLAGS = -Wall

check-env:
	@which $(CC) > /dev/null || (echo "Error: $(CC) not found. Install with 'sudo apt install build-essential'"; exit 1)

build: check-env
	$(CC) $(CFLAGS) -o laba1spo src/main.cpp

install: build
	install -Dm755 laba1spo $(DESTDIR)/usr/bin/laba1spo
	
uninstall:
	rm -f $(DESTDIR)/usr/bin/laba1spo
	
.PHONY: build install uninstall

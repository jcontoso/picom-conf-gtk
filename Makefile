CC ?= cc
SOURCES = $(wildcard src/*.c)
PKGCONFIG = $(shell which pkg-config)
CFLAGS = -Wno-deprecated-declarations $(shell $(PKGCONFIG) --cflags gtk+-3.0 libconfig)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0 libconfig) -lm
OBJS  = ${SOURCES:.c=.o}
PACKAGE = picom-conf-gtk

all: ${PACKAGE}
	
picom-conf-gtk: $(SOURCES)
	$(CC) $(^) -o ${PACKAGE} ${CFLAGS} ${LIBS}

clean:
	rm -f ${PACKAGE}
	
uninstall:
	rm -f /usr/local/bin/picom-conf-gtk
	rm -f /usr/share/icons/hicolor/64x64/apps/picom-conf.png
	rm -f /usr/share/applications/picom-conf-gtk.desktop

install:
	install -Dm0755 picom-conf-gtk /usr/local/bin/picom-conf-gtk
	install -Dm0755 res/picom-conf-gtk.desktop /usr/share/applications/picom-conf-gtk.desktop
	install -Dm0644 res/picom-conf.png /usr/share/icons/hicolor/64x64/apps/picom-conf.png

.PHONY: clean install uninstall


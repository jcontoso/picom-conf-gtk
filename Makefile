CC ?= cc
SOURCES = $(wildcard src/*.c)
PKGCONFIG = $(shell which pkg-config)
CFLAGS = -Wno-deprecated-declarations $(shell $(PKGCONFIG) --cflags gtk+-3.0 libconfig)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0 libconfig) -lm
PACKAGE = picom-conf-gtk

all: ${PACKAGE} po/tr_TR/$(PACKAGE).mo

picom-conf-gtk: $(SOURCES)
	$(CC) $(^) -o ${PACKAGE} ${CFLAGS} ${LIBS}

po/tr_TR/$(PACKAGE).mo: po/tr_TR/$(PACKAGE).po
	msgfmt $(^) --output-file=$@ 
	
clean:
	rm -f ${PACKAGE}
	rm -f po/tr_TR/$(PACKAGE).mo
		
uninstall:
	rm -f /usr/local/bin/picom-conf-gtk
	rm -f /usr/share/icons/hicolor/64x64/apps/picom-conf.png
	rm -f /usr/share/applications/picom-conf-gtk.desktop
	rm -f /usr/share/locale/tr_TR/LC_MESSAGES/$(PACKAGE).mo

install: ${PACKAGE}
	install -Dm0755 picom-conf-gtk /usr/local/bin/picom-conf-gtk
	install -Dm0755 res/picom-conf-gtk.desktop /usr/share/applications/picom-conf-gtk.desktop
	install -Dm0644 res/picom-conf.png /usr/share/icons/hicolor/64x64/apps/picom-conf.png
	install -Dm0644 po/tr_TR/$(PACKAGE).mo /usr/share/locale/tr/LC_MESSAGES/$(PACKAGE).mo

	
.PHONY: clean install uninstall



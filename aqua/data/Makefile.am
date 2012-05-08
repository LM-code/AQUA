#SUBDIRS = icons

gnomeappdir = ${datadir}/applications

gnomeapp_in_files = aqua.desktop.in
gnomeapp_DATA = $(gnomeapp_in_files:.desktop.in=.desktop)
	
appicondir = $(datadir)/pixmaps

pixmapsdir       = $(datadir)/pixmaps
pixmaps_DATA     = aqua.png

EXTRA_DIST = \
	$(gnomeapp_DATA) $(gnomeapp_in_files) \
	$(pixmaps_DATA)

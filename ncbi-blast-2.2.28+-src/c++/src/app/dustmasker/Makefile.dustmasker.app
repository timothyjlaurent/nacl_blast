# $Id: Makefile.dustmasker.app 372075 2012-08-14 20:17:07Z camacho $

REQUIRES = objects algo

ASN_DEP = seq

APP = dustmasker
SRC = main dust_mask_app

LIB = xalgodustmask seqmasks_io $(OBJREAD_LIBS) xobjutil \
	xobjread seqdb blastdb $(OBJMGR_LIBS:%=%$(STATIC))

LIBS = $(CMPRS_LIBS) $(NETWORK_LIBS) $(DL_LIBS) $(ORIG_LIBS)

CXXFLAGS = $(FAST_CXXFLAGS)
LDFLAGS  = $(FAST_LDFLAGS)


WATCHERS = camacho
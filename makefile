CC=g++.exe
CFLAGS=-Wall

ODIR=./obj
BDIR=./bin

LIBS=-lmingw32

MKDIR_P=mkdir -p

all: directories hack copy

copy:
	cp ./bin/hack.dll ./injector

# Directories that need to exist (that are not in the repository) are created here
directories: $(ODIR) $(BDIR)

$(ODIR):
	$(MKDIR_P) $(ODIR)

$(BDIR):
	$(MKDIR_P) $(BDIR)
# End directories

# All header files that need to be compiled go here
HL_COMMON=$(wildcard ./HLSDK/common/*.h)
HL_ENGINE=$(wildcard ./HLSDK/engine/*.h)
HL_MISC=$(wildcard ./HLSDK/misc/*.h)
DEPS=SDK.h $(HL_COMMON) $(HL_ENGINE) $(HL_MISC)

# All object files (which correspond to compiled .c files) go here
_OBJ=hack.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o:./%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# $@ means left side of :
# $^ means right side of :
# -shared to make a dll
# -fPIC for position independent code
hack: $(OBJ)
	$(CC) -shared -fPIC -o ./bin/$@.dll $^ $(CFLAGS) $(LIBS)

.PHONY: clean directories

clean:
	rm -f $(ODIR)/*.o

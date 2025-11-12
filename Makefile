CXX := g++

CXX_FLAGS := -std=c++11 -Wall -Wextra -O3 -g -MD $(shell $(ROOTSYS)/bin/root-config --libs)  -lMinuit -lGeom -lEG
CXX_INC := -I./inc/ $(shell $(ROOTSYS)/bin/root-config --cflags)

ENTRY_POINT := main
ENTRY_OBJDIR := main/obj
BINDIR := bin
INCDIR := inc
SRCDIR := src
OBJDIR := src/obj

MAINS := $(wildcard $(ENTRY_POINT)/*.cpp)
MAIN_OBJ := $(subst $(ENTRY_POINT),$(ENTRY_OBJDIR),$(subst .cpp,.o,$(MAINS)))
SRCS  := $(wildcard $(SRCDIR)/*.cpp)
OBJS  := $(subst $(SRCDIR),$(OBJDIR),$(subst .cpp,.o,$(SRCS)))
PROGRAMS := $(subst $(ENTRY_POINT),$(BINDIR),$(subst .cpp,,$(wildcard $(ENTRY_POINT)/*.cpp)))

.POHNY: clean

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXX_FLAGS) $(CXX_INC) -c -o $@ $<

$(ENTRY_OBJDIR)/%.o: $(ENTRY_POINT)/%.cpp
	$(CXX) $(CXX_FLAGS) $(CXX_INC) -c -o $@ $<

$(BINDIR)/%: $(ENTRY_OBJDIR)/%.o $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $@ $^

all: $(MAIN_OBJ) $(OBJS) $(DEPS)
	@for PROGRAM in $(PROGRAMS) ; do \
		make $$PROGRAM ; \
	done

config:
	@echo "make configration"
	@echo "OBS=${OBJS}"
	@echo "OBS=${DEPS}"
	@echo "PROGRAMS=${PROGRAMS}"

clean:
	@echo "Make clean ..."
	rm -f $(OBJS) $(MAIN_OBJ) $(PROGRAMS)
	rm -f $(ENTRY_OBJDIR)/*.d
	rm -f $(OBJDIR)/*.d
	rm -f $(BINDIR)/*
	rm -f AutoDict_*
	rm -f $(ENTRY_POINT)/obj/*.o

-include $(ENTRY_OBJDIR)/*.d
-include $(OBJDIR)/*.d

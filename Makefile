CXX:=g++

OUTPUT:=bojack
OBJECTS:=logger.o main.o

LOCATION:=$(shell pwd)

DBGDIR:=debug
DBGOUT:=$(DBGDIR)/$(OUTPUT)
DBGOBJS:=$(addprefix $(DBGDIR)/, $(OBJECTS))

CXXFLAGS:=-std=c++17  -Wall -Wextra
INCLUDE:=-I$(LOCATION)/include/
LIBRARIES:=-lpthread -lspdlog
DFLAGS:=$(CXXFLAGS) -DDEBUG -g -O0

RELDIR:= release
RELOUT:= $(RELDIR)/$(OUTPUT)
RELOBJS:= $(addprefix $(RELDIR)/, $(OBJECTS))

COMPILE:=$(CXX) $(CXXFLAGS) $(INCLUDE)
DCOMPILE:=$(CXX) $(DFLAGS) $(INCLUDE)

all: prep release

.PHONY: all clean debug prep release

debug: $(DBGOUT)

$(DBGOUT): $(DBGOBJS)
	$(DCOMPILE) -o $@ $^ $(LIBRARIES)

$(DBGDIR)/%.o: %.cpp
	$(DCOMPILE) -c $< -o $@

release: $(RELOUT)

$(RELOUT): $(RELOBJS)
	$(COMPILE) -o $@ $^ $(LIBRARIES)

$(RELDIR)/%.o: %.cpp
	$(COMPILE) -c $< -o $@

prep:
	@mkdir -p $(DBGDIR) $(RELDIR)

clean:
	rm -f $(RELOUT) $(RELOBJS) $(DBGOUT) $(DBGOBJS) *.o *.so *.out bojack
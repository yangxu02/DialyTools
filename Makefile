progsrsc = test_vclock.cpp

cppsrcs = $(wildcard *.cpp)
csrcs = $(wildcard *.c)

allobjs = $(cppsrcs:.cpp=.o)
allobjs += $(csrcs:.c=.o)

progs = $(progsrsc:.cpp=)
progobjs = $(progsrsc:.cpp=.o)

libobjs = $(filter-out $(progobjs), $(allobjs))

ProfileFlag = -pg
TraceFlag = -finstrument-functions
DebugFlag = -g

INCLUDE +=
CXX = g++
GCC = gcc
CPPFLAGS += -fpermissive -Wint-to-pointer-cast -Wwrite-strings
CFLAGS += -Wint-to-pointer-cast -Wwrite-strings
LD = g++
LDFLAGS += -lc -lrt -ldl -lstdc++

.PHONY: all clean

all: $(progs)

install:

$(lib):
	@echo "ar cr $(lib) $(libobjs)"
	@mkdir -p `dirname $(lib)`
	ar rc $@ $(libobjs)
	ranlib $@

$(progs): $(allobjs)
	@echo ">> Linking $@"
	$(LD) -o $@ $(@:=).o $(libobjs) $(LDFLAGS)

%.o: %.cpp
	@echo ">> Compiling $<"
	$(CXX) $(CPPFLAGS) -c $< -o $@ $(INCLUDE)

%.o: %.c
	@echo ">> Compiling $<"
	$(GCC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(libobjs) $(progobjs) $(lib) $(progs)


ifeq ($(DEBUG),true)
    OPT_CFLAGS   := -O0 -g3 -ftrapv -fstack-protector-all -D_FORTIFY_SOURCE=2
ifneq ($(OS),Windows_NT)
    OPT_CFLAGS   := $(OPT_CFLAGS) -fsanitize=address -fno-omit-frame-pointer
endif
    OPT_CXXFLAGS := $(OPT_CFLAGS) -D_GLIBCXX_DEBUG
    OPT_LDLIBS   := -lssp
else
ifeq ($(OPT),true)
    OPT_CFLAGS   := -flto -Ofast -march=native -DNDEBUG
    OPT_CXXFLAGS := $(OPT_CFLAGS)
    OPT_LDFLAGS  := -flto -Ofast -s
else
ifeq ($(LTO),true)
    OPT_CFLAGS   := -flto -DNDEBUG
    OPT_CXXFLAGS := $(OPT_CFLAGS)
    OPT_LDFLAGS  := -flto
else
    OPT_CFLAGS   := -O3 -DNDEBUG
    OPT_CXXFLAGS := $(OPT_CFLAGS)
    OPT_LDFLAGS  := -O3 -s
endif
endif
endif


WARNING_CFLAGS := -Wall -Wextra -Wformat=2 -Wstrict-aliasing=2 \
                  -Wcast-align -Wcast-qual -Wconversion \
                  -Wfloat-equal -Wpointer-arith -Wswitch-enum \
                  -Wwrite-strings -pedantic
WARNING_CXXFLAGS := $(WARNING_CFLAGS) -Weffc++ -Woverloaded-virtual


CC       := gcc
CXX      := g++
CAT      := cat
ECHO     := echo
CFLAGS   := -std=gnu++11 -pipe -fdiagnostics-color=always $(WARNING_CFLAGS) $(OPT_CFLAGS)
CXXFLAGS := -std=gnu++11 -pipe -fdiagnostics-color=always $(WARNING_CXXFLAGS) $(OPT_CXXFLAGS)
LDFLAGS  := -pipe $(OPT_LDFLAGS)
LDLIBS   := $(OPT_LDLIBS)
TARGET   := main
OBJ      := $(addsuffix .o, $(basename $(TARGET)))
SRC      := $(OBJ:.o=.cpp)
INPUTS   := $(sort $(wildcard input*.txt))

ifeq ($(OS),Windows_NT)
    TARGET := $(addsuffix .exe, $(TARGET))
else
    TARGET := $(addsuffix .out, $(TARGET))
endif

.SUFFIXES: .exe .o .out
.o.exe:
	$(CXX) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@
.o.out:
	$(CXX) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@
.o:
	$(CXX) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)

$(OBJ): $(SRC)


.PHONY: test
test: $(TARGET)
	@for input in $(INPUTS); do \
		i=`expr $$i + 1`; \
		$(ECHO) "========== input  $$i =========="; \
		$(CAT) $$input; \
		$(ECHO) "========== output $$i =========="; \
		./$< < $$input; \
		$(ECHO); \
	done


.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJ)
.PHONY: cleanobj
cleanobj:
	$(RM) $(OBJ)

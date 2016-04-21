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


CC           := gcc
CXX          := g++
ECHO         := echo
CAT          := cat
MKDIR        := mkdir -p
CP           := cp
RM           := rm -f
CTAGS        := ctags
CFLAGS       := -pipe -std=gnu11 $(WARNING_CFLAGS) $(OPT_CFLAGS)
CXXFLAGS     := -pipe -std=gnu++11 $(WARNING_CXXFLAGS) $(OPT_CXXFLAGS)
LDFLAGS      := -pipe $(OPT_LDFLAGS)
LDLIBS       := $(OPT_LDLIBS)
CTAGSFLAGS   := -R --languages=c,c++
TARGET       := main
SRCS         := $(addsuffix .cpp, $(basename $(TARGET)))
OBJS         := $(SRCS:.cpp=.o)
INPUTS       := $(sort $(wildcard input*.txt))

ifeq ($(OS),Windows_NT)
    TARGET := $(addsuffix .exe, $(TARGET))
else
    TARGET := $(addsuffix .out, $(TARGET))
endif

%.exe:
	$(CXX) $(LDFLAGS) $(filter %.c %.cpp %.cxx %.cc %.o, $^) $(LDLIBS) -o $@
%.out:
	$(CXX) $(LDFLAGS) $(filter %.c %.cpp %.cxx %.cc %.o, $^) $(LDLIBS) -o $@


.PHONY: all depends test syntax ctags clean cleanobj
all: $(TARGET)

$(TARGET): $(OBJS)

$(OBJS): $(SRCS)


test: $(TARGET)
	@for input in $(INPUTS); do \
		i=`expr $$i + 1`; \
		$(ECHO) "========== input  $$i =========="; \
		$(CAT) $$input; \
		$(ECHO) "========== output $$i =========="; \
		./$< < $$input; \
		$(ECHO); \
	done

syntax:
	$(CXX) $(SRCS) $(STD_CXXFLAGS) -fsyntax-only $(WARNING_CXXFLAGS) $(INCS) $(MACROS)

ctags:
	$(CTAGS) $(CTAGSFLAGS)

clean:
	$(RM) $(TARGET) $(OBJS)

cleanobj:
	$(RM) $(OBJS)

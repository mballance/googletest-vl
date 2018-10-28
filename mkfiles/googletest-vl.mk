
GOOGLETEST_VL_MKFILES_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

ifneq (1,$(RULES))

SRC_DIRS += $(GOOGLETEST_VL_MKFILES_DIR)/../src

GOOGLETEST_VL_SRC = $(notdir $(wildcard $(GOOGLETEST_VL_MKFILES_DIR)/../src/*.cpp))

else # Rules

libgoogletest-vl.o : $(GOOGLETEST_VL_SRC:.cpp=.o)
	$(Q)$(LD) -r -o $@ $(GOOGLETEST_VL_SRC:.cpp=.o)

endif

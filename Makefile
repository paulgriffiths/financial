# C++ financial library
# =====================
# Copyright 2013 Paul Griffiths
# Email: mail@paulgriffiths.net
#
# Distributed under the terms of the GNU General Public License.
# http://www.gnu.org/licenses/


# Variables section
# =================

# Library and executable names
OUT=libfinancial.a
TESTOUT=unittests
SAMPLEOUT=sample

# Install paths
LIB_INSTALL_PATH=/home/paul/lib/cpp
INC_INSTALL_PATH=/home/paul/include
HEADERS=financial.h basic_dcf.h common_financial_types.h

# Compiler and archiver executable names
AR=ar
CXX=g++

# Archiver flags
ARFLAGS=rcs

# Compiler flags
CXXFLAGS=-std=c++11 -pedantic -Wall -Wextra
CXX_DEBUG_FLAGS=-Weffc++ -ggdb -DDEBUG -DDEBUG_ALL
CXX_RELEASE_FLAGS=-Weffc++ -O3 -DNDEBUG
CXX_TEST_FLAGS=-ggdb -DDEBUG -DDEBUG_ALL

# Linker flags
LDFLAGS=
LD_TEST_FLAGS=-lboost_system -lboost_thread -lboost_unit_test_framework
LD_TEST_FLAGS+=-lstdc++
LD_TEST_FLAGS+=-lfinancial -L$(CURDIR)

# Object code files
MAINOBJ=main.o

OBJS=basic_dcf.o

TESTOBJS=tests/test_main.o
TESTOBJS+=tests/test_discount_factor.o
TESTOBJS+=tests/test_present_value.o
TESTOBJS+=tests/test_future_value.o
TESTOBJS+=tests/test_perpetuity.o
TESTOBJS+=tests/test_annuity.o
TESTOBJS+=tests/test_sinking_fund.o
TESTOBJS+=tests/test_loan_repayment.o

# Source and clean files and globs
SRCS=$(wildcard *.cpp *.h)
SRCS+=$(wildcard tests/*.cpp)

SRCGLOB=*.cpp *.h
SRCGLOB+=tests/*.cpp

CLNGLOB=$(OUT) $(TESTOUT) $(SAMPLEOUT)
CLNGLOB+=*~ *.o *.gcov *.out *.gcda *.gcno
CLNGLOB+=tests/*~ tests/*.o tests/*.gcov tests/*.out tests/*.gcda tests/*.gcno


# Build targets section
# =====================

default: debug

# debug - builds objects with debugging info
.PHONY: debug
debug: CXXFLAGS+=$(CXX_DEBUG_FLAGS)
debug: main

# release - builds with optimizations and without debugging info
.PHONY: release
release: CXXFLAGS+=$(CXX_RELEASE_FLAGS)
release: main

# tests - builds unit tests
.PHONY: tests
tests: CXXFLAGS+=$(CXX_TEST_FLAGS)
tests: LDFLAGS+=$(LD_TEST_FLAGS)
tests: testmain

# install - installs library and headers
.PHONY: install
install:
	@if [ ! -d $(INC_INSTALL_PATH)/paulgrif ]; then \
		mkdir $(INC_INSTALL_PATH)/paulgrif; fi
	@echo "Copying library to $(LIB_INSTALL_PATH)..."
	@cp $(OUT) $(LIB_INSTALL_PATH)
	@echo "Copying headers to $(INC_INSTALL_PATH)..."
	@cp $(HEADERS) $(INC_INSTALL_PATH)/paulgrif
	@echo "Done."

# sample - makes sample program
.PHONY: sample
sample: LDFLAGS+=-lfinancial
sample: main.o
	@echo "Linking sample program..."
	@$(CXX) -o $(SAMPLEOUT) main.o $(LDFLAGS)
	@echo "Done."

# clean - removes ancilliary files from working directory
.PHONY: clean
clean:
	-@rm $(CLNGLOB) 2>/dev/null

# lint - runs cpplint with specified options
.PHONY: lint
lint:
	@cpplint --verbose=5 --filter=-runtime/references,-build/header_guard,\
-readability/streams,-build/include,-legal/copyright,\
-runtime/threadsafe_fn,-whitespace/blank_line,-runtime/int,\
-build/namespaces \
$(SRCGLOB)

# check - runs cppcheck with specified options
.PHONY: check
check:
	@cppcheck --enable=all $(SRCGLOB)


# Executable targets section
# ==========================

# Main library
main: $(OBJS)
	@echo "Building library..."
	@$(AR) $(ARFLAGS) $(OUT) $(OBJS)
	@echo "Done."

# Unit tests executable
testmain: $(TESTOBJS)
	@echo "Linking unit tests..."
	@$(CXX) -o $(TESTOUT) $(TESTOBJS) $(LDFLAGS) 
	@echo "Done."


# Object files targets section
# ============================

# Sample program

main.o: main.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<


# Object files for library

basic_dcf.o: basic_dcf.cpp basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<


# Unit tests

tests/test_main.o: tests/test_main.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_discount_factor.o: tests/test_discount_factor.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_present_value.o: tests/test_present_value.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_future_value.o: tests/test_future_value.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_perpetuity.o: tests/test_perpetuity.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_annuity.o: tests/test_annuity.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_sinking_fund.o: tests/test_sinking_fund.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_loan_repayment.o: tests/test_loan_repayment.cpp \
	basic_dcf.h
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<


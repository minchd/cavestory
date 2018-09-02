# 		Created on: Sep 1, 2018
#		Author: minch.david
#
# Makefile is dependent on project structure of main proj with sub dirs for build, include, obj, and src
# currently setu for debug with extra devug info thus level 3
# also includes SDL2 library
#
#


NAME := Cavestory
SRC_DIR := ./src
OBJ_DIR := ./obj
INC_DIR := ./include
BUILD_DIR := ./build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LIBS=-lSDL2
CC=g++
CCFLAGS = -Wall -ggdb3
CFLAGS=-I$(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CCFLAGS) -o $@ $< $(CFLAGS)

$(NAME): $(OBJ_FILES)
	$(CC) $(CCFLAGS) -o $(BUILD_DIR)/$@ $^ $(CFLAGS) $(LIBS) 

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BUILD_DIR)/*.*

# 方便起见一般都会先定义编译器链接器
CC = gcc 
LD = gcc
#--------------------------------------------------
TOP_PATH := $(shell pwd)
SRC_PATH := $(TOP_PATH)/src/
BIN_PATH := $(TOP_PATH)/bin/
OBJ_PATH := $(TOP_PATH)/obj/
# -I指定头文件目录
INC_PATH = -I. \
           -I$(TOP_PATH)/include 

# -L指定库文件目录，-l指定静态库名字(去掉文件名中的lib前缀和.a后缀)
LIB_PATH = -L. \
         = -L$(TOP_PATH)/lib

#--------------------------------------------------

#compile and lib parameter
#编译参数
LDFLAGS		:=
DEFINES		:=
CFLAGS		:= -g -Wall -O3 $(DEFINES) $(INC_PATH)
CXXFLAGS	:= $(CFLAGS) -DHAVE_CONFIG_
#---------------------------------------------------
# 正则表达式表示目录下所有.c文件，相当于：SRCS = main.c a.c b.c
SRCS = $(wildcard $(SRC_PATH)*.c)

# OBJS表示SRCS中把列表中的.c全部替换为.o，相当于：OBJS = main.o a.o b.o
#OBJS = $(patsubst %c, %o, $(SRCS))
#$(patsubst %.cpp, %.o, $(SRCS))表示SRCS中把列表中的.c全部替换为.o
#$(notdir $(patsubst %.c, %.o, $(SRCS))))表示去除替换成.o文件的路径
#$(addprefix   表示为去除路径名的.o文件加上路径名$(OBJ_PATH)
OBJS=$(addprefix $(OBJ_PATH), $(notdir $(patsubst %.c, %.o, $(SRCS))))

#---------------------------------------------------
# 可执行文件的名字
TARGET = hello

# .PHONE伪目标，具体含义百度一下一大堆介绍
.PHONY:all clean test

# 要生成的目标文件
all: $(TARGET)

# 第一行依赖关系：冒号后面为依赖的文件，相当于Hello: main.o a.o b.o
# 第二行规则：$@表示目标文件，$^表示所有依赖文件，$<表示第一个依赖文件
$(TARGET): $(OBJS)
	@test -d $(BIN_PATH)||mkdir -p $(BIN_PATH) 
	@$(LD) -o $@ $^ 

# 上一句目标文件依赖一大堆.o文件，这句表示将$(OBJS)所有.o的扩展名替换成.c的文件
$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@test -d $(OBJ_PATH)||mkdir -p $(OBJ_PATH) 
	@$(CC) -o  $@ -c $< $(CFLAGS) 

# make clean删除所有.o和目标文件
clean:
	@rm -f $(OBJS) $(BIN_PATH)*

test:
	echo "PWD     = $(PWD)"
	echo "TOP_DIR = $(TOP_DIR)"
	echo "SRC_DIR = $(SRC_DIR)"
	echo "OBJ_DIR = $(OBJ_DIR)"
	echo "BIN_DIR = $(BIN_DIR)"
	echo "INC_DIR = $(INC_DIR)"
	echo "SRCS = $(SRCS)"
	echo "OBJS = $(OBJS)"
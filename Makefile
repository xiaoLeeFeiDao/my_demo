# Makefile

# 编译器设置
CXX = g++             # C++ 编译器
CXXFLAGS = -Wall -g    # 编译选项，这里设置了警告和调试信息

# 源文件目录和目标文件目录
SRCDIR := . cpp_learn demo       # 源文件目录列表
OBJDIR := obj                   # 目标文件目录

# 获取所有的.cpp文件列表
SRCS_CPP := $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.cpp))

# 将.cpp文件列表转换为对应的目标文件列表
OBJS_CPP := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(SRCS_CPP)))

# 可执行文件名
TARGET := myprogram

# 默认目标，即 make 命令会执行的目标
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(OBJS_CPP) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(OBJS_CPP) -o $(TARGET)

# 创建目标文件目录
$(OBJDIR):
	mkdir -p $(OBJDIR)

# 编译每个.cpp文件为目标文件
$(OBJDIR)/%.o: $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.cpp)) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I $(dir $(filter %/$*, $(SRCS_CPP))) -c $(filter %/$*.cpp, $(SRCS_CPP)) -o $@

# 清理生成的文件
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rm -rf $(OBJDIR)

# 声明一些伪目标，以避免冲突
.PHONY: all clean

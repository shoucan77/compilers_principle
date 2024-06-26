cmake_minimum_required(VERSION 3.12)

# 设置工程属性，如版本，开发语言等
project(calculator VERSION 1.0.0.2 LANGUAGES CXX)

# 是否输出Bison语法分析时是否输出自动机， 默认输出
# 如果修改为OFF，请删除cmake_build_debug后重新build
set(BISON_OUTPUT_GRAPH OFF CACHE BOOL "Enable/Disable output of a graph of the automaton for Bison")

# 这个目前没有用处，可删除
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 默认设置为ON，这里可注释掉。开启时会产生compile_commands.json的文件，有了这个文件才能识别出clang-tidy的配置
# Generates a `compile_commands.json` that can be used for autocompletion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable/Disable output of compile commands during generation.")

# 禁止MSVC编译时出现C4819警告
if(MSVC)
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

# graphviz查找文件
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

# 查找Java，若没有安装则错误。因ANTLR4需要，如果不使用ANTLR4时可删除
find_package(Java COMPONENTS Runtime REQUIRED)

# 因AST输出图片需要借助Graphviz提供的C++接口来实现，因此若Graphviz没有安装则出错
# 查找graphviz库是否在系统中安装，若安装则设置一系列的变量，如LIBGVC_INCLUDE_DIRS等
find_package(Graphviz REQUIRED)

# 查找flex工具，找不到则出错，注意设置PATHS的路径；FLEX_EXECUTABLE记录flex程序的位置
# 请优先使用find_package，不行用find_program，指定flex的位置
# 注释下一行可查看都在哪里查找路径了
# set(CMAKE_FIND_DEBUG_MODE TRUE)
find_package(FLEX REQUIRED)

# find_program(FLEX_EXECUTABLE NAMES flex win_flex PATHS C:/ToolsApp/msys64/usr/bin REQUIRED)
# message(STATUS ${FLEX_EXECUTABLE})

# 检查查找的flex是否时win_flex
string(FIND ${FLEX_EXECUTABLE} "win_flex.exe" result)

if(NOT ${result} EQUAL -1)
	set(WINFLEX_FOUND True)
else()
	set(WINFLEX_FOUND False)
endif()

# 查找bison工具，找不到则出错，注意设置PATHS的路径；BISON_EXECUTABLE记录bison程序的位置
# 请优先使用find_package，不行用find_program，指定bison的位置
find_package(BISON REQUIRED)

# find_program(BISON_EXECUTABLE NAMES bison win_bison PATHS C:/ToolsApp/msys64/usr/bin REQUIRED)
# message(STATUS ${BISON_EXECUTABLE})

# 检查查找的flex是否时win_flex
string(FIND ${BISON_EXECUTABLE} "win_bison.exe" result)

if(NOT ${result} EQUAL -1)
	set(WINBISON_FOUND True)
else()
	set(WINBISON_FOUND False)
endif()

# 设置antlr-4.12.0-complete的位置
set(ANTLR4_JAR_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/antlr4/antlr-4.12.0-complete.jar)
message(STATUS ${ANTLR4_JAR_LOCATION})

# 查找antlr4-runtime的包是否存在，若不存在则出错
find_package(ANTLR4 REQUIRED)
message(STATUS ${ANTLR4_INCLUDE_DIR})

# flex工具的输入和输出文件
set(FLEX_GEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/frontend/flexbison/autogenerated)
set(FLEX_INPUT
	${CMAKE_CURRENT_SOURCE_DIR}/frontend/flexbison/Calculator.l
)
set(FLEX_OUTPUT
	${FLEX_GEN_DIR}/CalculatorFlex.cpp
	${FLEX_GEN_DIR}/CalculatorFlex.h
)

# bison工具的输入和输出文件
set(BISON_GEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/frontend/flexbison/autogenerated)
set(BISON_INPUT
	${CMAKE_CURRENT_SOURCE_DIR}/frontend/flexbison/Calculator.y
)
set(BISON_OUTPUT
	${BISON_GEN_DIR}/CalculatorBison.cpp
	${BISON_GEN_DIR}/CalculatorBison.h
)

# antlr4工具的输入和输出文件
set(ANTLR4_GEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/frontend/antlr4/autogenerated)
set(ANTLR4_INPUT
	${CMAKE_CURRENT_SOURCE_DIR}/frontend/antlr4/Calculator.g4
)
set(ANTLR4_OUTPUT
	${ANTLR4_GEN_DIR}/CalculatorBaseVisitor.cpp
	${ANTLR4_GEN_DIR}/CalculatorBaseVisitor.h
	${ANTLR4_GEN_DIR}/CalculatorVisitor.cpp
	${ANTLR4_GEN_DIR}/CalculatorVisitor.h
	${ANTLR4_GEN_DIR}/CalculatorLexer.cpp
	${ANTLR4_GEN_DIR}/CalculatorLexer.h
	${ANTLR4_GEN_DIR}/CalculatorParser.cpp
	${ANTLR4_GEN_DIR}/CalculatorParser.h
)

# 前端源代码集合
set(FRONTEND_SRCS

	# 前端共性代码
	frontend/AST.cpp
	frontend/AST.h
	frontend/Graph.cpp
	frontend/Graph.h
	frontend/FrontEndExecutor.h
	frontend/AttrType.h

	# Flex与Bison相关代码
	${FLEX_OUTPUT}
	${BISON_OUTPUT}
	frontend/flexbison/FlexBisonExecutor.h
	frontend/flexbison/FlexBisonExecutor.cpp
	frontend/flexbison/FlexLexer.h
	frontend/flexbison/BisonParser.h

	# ANTLR4相关代码
	${ANTLR4_OUTPUT}
	frontend/antlr4/Antlr4CSTVisitor.cpp
	frontend/antlr4/Antlr4CSTVisitor.h
	frontend/antlr4/Antlr4Executor.cpp
	frontend/antlr4/Antlr4Executor.h

	# 递归下降分析法
	frontend/recursivedescent/RecursiveDescentFlex.cpp
	frontend/recursivedescent/RecursiveDescentFlex.h
	frontend/recursivedescent/RecursiveDescentParser.cpp
	frontend/recursivedescent/RecursiveDescentParser.h
	frontend/recursivedescent/RecursiveDescentExecutor.h
	frontend/recursivedescent/RecursiveDescentExecutor.cpp
)

# 后端源代码集合
set(BACKEND_SRCS

	# 后端共性代码
	backend/CodeGenerator.cpp
	backend/CodeGenerator.h
	backend/CodeGeneratorAsm.cpp
	backend/CodeGeneratorAsm.h

	# 后端通过指令解释执行
	backend/simulation/CodeSimulator.cpp
	backend/simulation/CodeSimulator.h

	# 后端产生ARM32汇编指令
	backend/arm32/ILocArm32.cpp
	backend/arm32/ILocArm32.h
	backend/arm32/InstSelectorArm32.cpp
	backend/arm32/InstSelectorArm32.h
	backend/arm32/PlatformArm32.cpp
	backend/arm32/PlatformArm32.h
	backend/arm32/CodeGeneratorArm32.cpp
	backend/arm32/CodeGeneratorArm32.h
)

# 中间IR(DragonIR)源代码集合
set(IR_SRCS
	DragonIR/IRInst.h
	DragonIR/IRInst.cpp
	DragonIR/IRCode.h
	DragonIR/IRCode.cpp
	DragonIR/IRGenerator.cpp
	DragonIR/IRGenerator.h
)

# 符号表等共通化代码集合
set(COMMON_SRCS
	common/Common.cpp
	common/Common.h
	common/ValueType.h
	common/ValueType.cpp
	common/Value.cpp
	common/Value.h
	common/Function.cpp
	common/Function.h
	common/SymbolTable.cpp
	common/SymbolTable.h
)

# 系统差异性代码集合
set(UTILS_SRCS
	utils/getopt-port.cpp
	utils/getopt-port.h
)

# 优化源代码集合
# TODO 增加优化时可在这里指定源代码的相对路径
set(OPT_SRCS)

# 配置创建一个可执行程序，以及该程序所依赖的所有源文件、头文件等
add_executable(${PROJECT_NAME}

	# 主程序
	main.cpp

	# 前端源代码
	${FRONTEND_SRCS}

	# 后端源代码
	${BACKEND_SRCS}

	# 符号表共性代码
	${COMMON_SRCS}

	# 中间IR代码
	${IR_SRCS}

	# 优化代码，暂时未用
	${OPT_SRCS}

	# 操作系统差异化代码，VC编译时使用
	${UTILS_SRCS}
)

# 设置语言标准C++17，可根据需要调整
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
)

## LLDB调试运行时string不能显示，这是由于clang默认优化时减少调试信息导致的，因此这里指定选项不要优化调试信息
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
	target_compile_options(${PROJECT_NAME} PRIVATE -fstandalone-debug)
endif()

# -Wno-unused-function避免无用函数警告
# -Wno-write-strings避免c++提示字符串常量转换char*的警告
# -Werror强制警告当作错误处理
# -Wall尽可能多的让编译器提示警告和错误
# __STDC_VERSION__的目的是警告产生的flex源文件出现INT8_MAX警告等
if(MSVC)
	target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS __STDC_VERSION__=199901)
else()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wno-write-strings -Wno-unused-function)
endif()

# 引入graphviz库的头文件，防止编译时找不到graphviz的头文件
target_include_directories(${PROJECT_NAME} PRIVATE
	${Graphviz_INCLUDE_DIRS}
	${ANTLR4_INCLUDE_DIR}
	common
	utils
	frontend
	frontend/antlr4
	frontend/antlr4/autogenerated
	frontend/flexbison
	frontend/flexbison/autogenerated
	frontend/recursivedescent
	DragonIR
	backend
	backend/simulation
	backend/arm32
)

# 指定graphviz的库文件以及位置，防止链接时找不到graphviz的库函数
target_link_libraries(${PROJECT_NAME} PRIVATE ${Graphviz_LIBRARIES})

# 指导antlr4的库名，防止链接时找不到antlr4-runtime
target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_LIBRARY})

# 采用win_flex产生词法文件时减少OS系统差异的问题
if(CMAKE_HOST_WIN32)
	if(WINFLEX_FOUND)
		set(FLEX_OPTION "--wincompat")
	else()
		set(FLEX_OPTION "--nounistd")
	endif()
endif()

# 通过flex产生词法分析源代码
add_custom_command(
	OUTPUT
	${FLEX_OUTPUT}
	COMMAND
	${FLEX_EXECUTABLE} ${FLEX_OPTION} -o ${FLEX_GEN_DIR}/CalculatorFlex.cpp --header-file=${FLEX_GEN_DIR}/CalculatorFlex.h ${FLEX_INPUT}
	DEPENDS
	${FLEX_INPUT}
	WORKING_DIRECTORY
	${FLEX_GEN_DIR}
)

# Window版和Linux版产生头文件时选项名字不一样，根据不同系统设置
if(CMAKE_HOST_WIN32)
	if(WINBISON_FOUND)
		set(BISON_HEADFILE_OPTION "--defines")
	else()
		set(BISON_HEADFILE_OPTION "--header")
	endif()
else()
	set(BISON_HEADFILE_OPTION "--defines")
endif()

if(BISON_OUTPUT_GRAPH)
	set(BISON_EXTRA_OPTION "--graph=${FLEX_GEN_DIR}/CalculatorBison.dot")
else()
	set(BISON_EXTRA_OPTION)
endif()

# 通过bison生成语法分析源代码
add_custom_command(
	OUTPUT
	${BISON_OUTPUT}
	COMMAND
	${BISON_EXECUTABLE} -d --debug ${BISON_EXTRA_OPTION} -o ${FLEX_GEN_DIR}/CalculatorBison.cpp ${BISON_HEADFILE_OPTION}=${FLEX_GEN_DIR}/CalculatorBison.h ${BISON_INPUT}
	DEPENDS
	${BISON_INPUT}
	WORKING_DIRECTORY
	${BISON_GEN_DIR}
)

if(BISON_OUTPUT_GRAPH)
	# 转换dot文件成png文件
	add_custom_command(
		TARGET ${PROJECT_NAME}
		POST_BUILD
		COMMAND
		dot -Tpng -o ${FLEX_GEN_DIR}/CalculatorBison.png ${FLEX_GEN_DIR}/CalculatorBison.dot
		COMMENT
		"dot2png"
		VERBATIM
	)
endif()

# 通过antlr4.12.0生成词法与语法分析源代码
# WORKING_DIRECTORY指定工作目录时Mac平台有问题，因此使用绝对地址
add_custom_command(
	OUTPUT
	${ANTLR4_OUTPUT}
	COMMAND
	${Java_JAVA_EXECUTABLE} -jar ${ANTLR4_JAR_LOCATION} -Dlanguage=Cpp -no-listener -visitor -o ${ANTLR4_GEN_DIR} Calculator.g4
	DEPENDS
	${ANTLR4_INPUT}
	WORKING_DIRECTORY
	${ANTLR4_GEN_DIR}/..
)

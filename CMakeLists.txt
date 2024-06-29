cmake_minimum_required(VERSION 3.10)
project(timeDebuger)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置Qt的安装路径
set(Qt6_DIR "D:/Qt/6.5.3/msvc2019_64/lib/cmake")
set(CMAKE_PREFIX_PATH ${Qt6_DIR})
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# 查找Qt6的组件
find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

# 递归查找源文件
file(GLOB_RECURSE HEADER_FILES "./src/*.h")
file(GLOB_RECURSE SOURCE_FILES "./src/*.cpp")
file(GLOB_RECURSE UI_FILES "./ui/*.ui") # 添加这一行递归查找 .ui 文件

# 添加可执行文件
add_executable(timeDebuger ${HEADER_FILES} ${SOURCE_FILES} ${UI_FILES}) # 添加 ${UI_FILES}

# 设置包含目录
target_include_directories(timeDebuger
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/asmTableWidget
)

# 链接Qt6的模块
target_link_libraries(timeDebuger
    PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
)

# 将源文件按目录分组
source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("UI Files" FILES ${UI_FILES})
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(PISCINE_C__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/rush01/GKrellM/5.7/clang_64/include")
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/rush01/GKrellM/5.7/clang_64/lib)
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/rush01/GKrellM/5.7/clang_64")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/rush01/GKrellM/5.7/clang_64/lib")

set(QT_BIN "TEMP/QT_CREATOR_BUILD/debug")
set(Qt5_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rush01/GKrellM/5.7/clang_64/lib/cmake/Qt5")

#################################################################
#Base QT directory
set(QT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/rush01/GKrellM/5.7/clang_64")
set(QT_LIBRARIES Qt5::Core Qt5::Gui Qt5::Network Qt5::OpenGL
		Qt5::Svg Qt5::Xml Qt5::UiTools)
#Libraries required. Probably the same as above minus the '::'. find_package() will be called on these
find_package(Qt5 COMPONENTS Core Gui Multimedia Network OpenGL  Svg  Xml UiTools)
#################################################################

file(GLOB_RECURSE USER_SOURCES "*.c" "*.h" "*.cpp" "*.hpp" "*.pro" "*.ui" "Makefile" "*.zip" "*.md")

FUNCTION (EXCLUDE_FILES_FROM_DIR_IN_LIST _InFileList _excludeDirName _verbose)
  foreach (ITR ${_InFileList})
    if ("${ITR}" MATCHES "(.*)${_excludeDirName}(.*)")                   # Check if the item matches the directory name in _excludeDirName
      list (REMOVE_ITEM _InFileList ${ITR})                              # Remove the item from the list
    endif ("${ITR}" MATCHES "(.*)${_excludeDirName}(.*)")
  endforeach(ITR)
  set(SOURCE_FILES ${_InFileList} PARENT_SCOPE)                          # Return the SOURCE_FILES variable to the calling parent
ENDFUNCTION (EXCLUDE_FILES_FROM_DIR_IN_LIST)
EXCLUDE_FILES_FROM_DIR_IN_LIST("${USER_SOURCES}" "/src_REF/" FALSE)

add_executable(PISCINE_C__ ${SOURCE_FILES})

# Linking Editor with Qt libraries
target_link_libraries(PISCINE_C__  Qt5::Core Qt5::Gui Qt5::Network Qt5::OpenGL
		Qt5::Svg Qt5::Xml Qt5::UiTools)



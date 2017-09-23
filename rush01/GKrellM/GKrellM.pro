# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    GKrellM.pro                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


TEMPLATE = app

CONFIG	-= app_bundle

CONFIG	+= debug
CONFIG	+= silent
DEFINES += QT_NO_DEBUG_OUTPUT
DEFINES += QT_NO_DEBUG

QT		+= core
QT		+= charts
QT		+= datavisualization
QT		+= 3dcore 3drender 3dinput 3dquick qml quick 3dquickextras 3dextras

PRO_PATH=$$PWD

CMAKE_PREFIX_PATH	= $$PRO_PATH/5.7/clang_64
CMAKE_MODULE_PATH	= $$PRO_PATH/5.7/clang_64/lib
Qt5_DIR				= $$PRO_PATH/5.7/clang_64/lib/cmake/Qt5

# suppress the default RPATH if you wish
#QMAKE_LFLAGS_RPATH=
# add your own with quoting gyrations to make sure $ORIGIN gets to the command line unexpanded
#QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\GKrellM/5.7/clang_64/lib\'"
QMAKE_RPATHDIR		= $$PRO_PATH/5.7/clang_64/lib


MAKEFLAGS	+= --silent

win32
{
	debug
	{
		CONFIG += console
	}
}

macx:ICON		= LOGO.icns
ICON			= LOGO.icns



LIBS			= -lncurses -lpthread

TARGET			= ft_gkrellm
INCLUDEPATH		+= .

# Input
HEADERS		+=	displays/MGR_QT.hpp				\
				displays/MGR_NCURSES.hpp		\
				MGR_Terminal.hpp				\
				modules/IMonitorModule.hpp		\
				modules/Module_CPU.hpp			\
				modules/Module_DISK.hpp			\
				modules/Module_HOST.hpp			\
				modules/Module_MemRegions.hpp	\
				modules/Module_Network.hpp		\
				modules/Module_OS.hpp			\
				modules/Module_PONY.hpp			\
				modules/Module_PROC.hpp			\
				modules/Module_RAM.hpp			\
				modules/Module_TIME.hpp			\
				modules/Module_VM.hpp			\
				modules/Module_CAT.hpp			\
				MGR_Module.hpp					\
				displays/IMonitorDisplay.hpp	\
				widgets/barspainter.hpp			\
				widgets/graphmulticolorpainter.hpp\
				widgets/graphpainter.hpp		\
				widgets/ramwidget.hpp			\
				widgets/cpuwidget.hpp			\
				widgets/painterutils.hpp		\
				widgets/performancepainter.hpp	\
				widgets/performancewidget.hpp	\
				widgets/dataquery.hpp			\
				widgets/memoryquery.hpp			\
				widgets/cpuquery.hpp			\
				widgets/cpudataquery.hpp		\
				widgets/ramdataquery.hpp


FORMS		+=	gkrellm.ui
SOURCES		+=	displays/MGR_QT.cpp				\
				main.cpp						\
				displays/MGR_NCURSES.cpp		\
				MGR_Terminal.cpp				\
				MGR_Terminal_Keyboard.cpp		\
				MGR_Terminal_Time.cpp			\
				MGR_Terminal_Render.cpp			\
				MGR_Terminal_Update.cpp			\
				modules/IMonitorModule.cpp		\
				modules/Module_CPU.cpp			\
				modules/Module_DISK.cpp			\
				modules/Module_HOST.cpp			\
				modules/Module_MemRegions.cpp	\
				modules/Module_Network.cpp		\
				modules/Module_OS.cpp			\
				modules/Module_PONY.cpp			\
				modules/Module_PROC.cpp			\
				modules/Module_RAM.cpp			\
				modules/Module_TIME.cpp			\
				modules/Module_VM.cpp			\
				modules/Module_CAT.cpp			\
				MGR_Module.cpp					\
				MGR_Module_Update.cpp			\
				displays/IMonitorDisplay.cpp	\
				widgets/barspainter.cpp			\
				widgets/cpuwidget.cpp			\
				widgets/graphmulticolorpainter.cpp\
				widgets/graphpainter.cpp		\
				widgets/painterutils.cpp		\
				widgets/performancepainter.cpp	\
				widgets/performancewidget.cpp	\
				widgets/ramwidget.cpp			\
				widgets/dataquery.cpp			\
				widgets/memoryquery.cpp			\
				widgets/cpuquery.cpp			\
				widgets/cpudataquery.cpp		\
				widgets/ramdataquery.cpp

OTHER_FILES	+= 									\
				main.qml						\
				AdsMaterial.qml					\
				AdsEffect.qml					\
				ShadowMapLight.qml				\
				ShadowMapFrameGraph.qml			\
				Pony.qml						\
				Cat.qml							\
				GroundPlane.qml					\

RESOURCES	+= \
				shadow-map-qml.qrc \
				obj.qrc

QMAKE_CXX				=	clang++

QMAKE_CXXFLAGS			+=	-Wall -Wextra -Werror

QMAKE_CXXFLAGS			+=	-std=c++11
QMAKE_CXXFLAGS			+=	-mmacosx-version-min=10.9
QMAKE_LFLAGS			+=	-mmacosx-version-min=10.9


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

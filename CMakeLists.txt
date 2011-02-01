cmake_minimum_required(VERSION 2.6)
	PROJECT(application)
	# untested on windows. Should work.
	if (WIN32)
	
		set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
		FILE(GLOB SRCS *.cpp)
		FILE(GLOB HDRS *.h)
		ADD_EXECUTABLE(ogre3dtut
			${SRCS}
			${HDRS}
			)
		
		INCLUDE_DIRECTORIES(;$(OGRE_HOME)/include)
		LINK_DIRECTORIES(
			$(OGRE_HOME)/boost_1_42/lib
			$(OGRE_HOME)/lib/Debug
			$(OGRE_HOME)/lib/Release
		)
	
		TARGET_LINK_LIBRARIES(
				application
				general opengl32.lib
				debug OgreMain_d.lib
				debug OIS_d.lib
				optimized OgreMain.lib
				optimized OIS.lib
				)
	
	else (WIN32)
		# linux
		set(CMAKE_MODULE_PATH 
			/usr/lib/OGRE/cmake
			)
		set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
		FIND_PACKAGE(OpenGL)
		FIND_PACKAGE(OGRE)
		FIND_PACKAGE(OIS)
		
		INCLUDE_DIRECTORIES(
			${OpenGL_INCLUDE_DIR}
			${OGRE_INCLUDE_DIRS}
			${OIS_INCLUDE_DIRS}
			${PROJECT_SOURCE_DIR}/include
			)
		
		FILE(GLOB SRCS src/*.cpp)
		FILE(GLOB HDRS src/*.h)
		
		ADD_EXECUTABLE(application 
			${SRCS}
			${HDRS}
		)
		TARGET_LINK_LIBRARIES(application
		${OpenGL_LIBRARIES}
		${OIS_LIBRARIES}
		${OGRE_LIBRARIES}
		)
	endif ()
	

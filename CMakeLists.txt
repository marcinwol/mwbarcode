cmake_minimum_required(VERSION 2.8)
project(MwBarCode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=false")


find_package(Boost COMPONENTS filesystem system program_options regex REQUIRED)
find_package(ImageMagick COMPONENTS Magick++ MagickCore REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(ImageMagick_FOUND)
    include_directories(${ImageMagick_INCLUDE_DIRS})
    MESSAGE( STATUS "ImageMagick_INCLUDE_DIRS:         " ${ImageMagick_INCLUDE_DIRS} )
endif()

set(SOURCE_FILES main.cpp)
add_executable(mwbarcode ${SOURCE_FILES} src/MwBarCode.cpp src/MwBarCode.h src/MagickHeaders.h src/BoostHeaders.h src/utils.cpp src/utils.h ext/infix_iterator.h ext/format.cpp ext/format.h src/MwImage.cpp src/MwImage.h src/MwResolution.cpp src/MwResolution.h src/MwColor.cpp src/MwColor.h ext/filesignature.cpp ext/filesignature.h src/ProcessImages.cpp src/ProcessImages.h)

if(Boost_FOUND)
    target_link_libraries(mwbarcode ${Boost_LIBRARIES})
endif()

if(ImageMagick_FOUND)
    target_link_libraries(mwbarcode ${ImageMagick_LIBRARIES})
    MESSAGE( STATUS "ImageMagick_LIBRARIES:         " ${ImageMagick_LIBRARIES} )
endif()

install (TARGETS mwbarcode DESTINATION ./)
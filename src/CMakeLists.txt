set(LIBNAME ${PROJECT_NAME}_lib)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/MultiLineAccumulator.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VResult.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/XmlClosingElementInterpreter.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/XmlCommentElementInterpreter.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/XmlElementContentsInterpreter.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/XmlElementInterpreter.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/XmlEmptyElementInterpreter.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/XmlOpeningElementInterpreter.cpp)

add_library(${LIBNAME} STATIC ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)
target_compile_features(${LIBNAME} PRIVATE cxx_std_14)

INSTALL(TARGETS ${LIBNAME} DESTINATION lib)
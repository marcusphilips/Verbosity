CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(Verbosity)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_EXECUTABLE(a.out
    definition.cpp
    partOfSpeech.cpp
    main.cpp
    word.cpp
)

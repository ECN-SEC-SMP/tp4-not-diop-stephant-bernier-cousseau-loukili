cmake_minimum_required(VERSION 3.28)

project(TP4) #Modify this

set (CMAKE_CXX_STANDARD 14) #Set CPP standard

set(SOURCE_FILES    main.cpp
                    Constructible.cpp
                    Parcelle.cpp
                    Point2D.cpp
                    ZoneAgricole.cpp
                    ZoneAUrbaniser.cpp
                    ZoneUrbaine.cpp
                    ) #Add source files here

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
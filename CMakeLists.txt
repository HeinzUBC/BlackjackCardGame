cmake_minimum_required(VERSION 3.16)
project(BlackjackCardGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackjackCardGame main.cpp PlayingCard.h Player.cpp Player.h RandomNumberSimulation.h PlayingCard.cpp GameEngine.cpp GameEngine.h)
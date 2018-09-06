cmake_minimum_required(VERSION 3.12)
project(TsLinuxNotifications)

set(CMAKE_CXX_STANDARD 11)

add_executable(TsLinuxNotifications include/clientlib_publicdefinitions.h include/public_definitions.h include/public_errors.h include/public_errors_rare.h include/public_rare_definitions.h plugin.h plugin.c include/ts3_functions.h)
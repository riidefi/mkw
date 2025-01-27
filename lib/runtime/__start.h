#pragma once

#ifdef __cplusplus
#error "C++ not supported during init"
#endif

#include <rk_types.h>

/// Entrypoint of the game.
void __start();

/// Resets the system if the infamous rescue combo (left, right, down, up, etc)
/// was pressed on GameCube controller 4 during startup.
void __check_pad3();

/// Sets the "debug BBA" flag (GameCube Broadband Adapter).
void __set_debug_bba();
/// Gets the value of the "debug BBA" flag (GameCube Broadband Adapter).
u8 __get_debug_bba();

/// Clears all registers.
void __init_registers();

/// Loads the DOL by copying sections into MEM1 and clears bss.
void __init_data();

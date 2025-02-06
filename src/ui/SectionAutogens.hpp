#pragma once

#include <decomp.h>

#include <rk_types.h>
#include <host_system/RKScene.hpp>

extern "C" {
void Section_addActivePage(void*, int);
void Section_addPage(void*, int);
}

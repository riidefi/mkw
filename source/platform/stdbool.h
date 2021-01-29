#pragma once

#ifndef MSL_STDBOOL
#define MSL_STDBOOL

#ifndef __cplusplus
	typedef _Bool bool;

	#define true ((_Bool)1)
	#define false ((_Bool)0)
#endif // __cplusplus

#endif // MSL_STDBOOL
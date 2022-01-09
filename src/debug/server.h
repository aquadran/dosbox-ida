/*
       IDA Pro remote debugger server
*/

#include <fpro.h>
#include <expr.hpp>
#include <signal.h>

#include <map>
#include <algorithm>

#define __SINGLE_THREADED_SERVER__
#define DEBUGGER_ID DEBUGGER_ID_X86_DOSBOX_EMULATOR

#ifdef __X64__
#define SYSBITS " 64-bit"
#else
#define SYSBITS " 32-bit"
#endif

#include "tcpip.h"

#ifdef __SINGLE_THREADED_SERVER__
#  define __SERVER_TYPE__ "ST"
#else
#  define __SERVER_TYPE__ "MT"
#endif

#include "debmod.h"
#include "rpc_hlp.h"
#include "rpc_server.h"

extern rpc_server_list_t clients_list;

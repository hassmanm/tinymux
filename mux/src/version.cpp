// version.cpp -- Version information.
//
// $Id: version.cpp,v 1.2 2002-06-04 00:47:28 sdennis Exp $
//

#include "copyright.h"
#include "autoconf.h"
#include "config.h"
#include "externs.h"

#include "_build.h"

void do_version(dbref executor, dbref caller, dbref enactor, int extra)
{
    notify(executor, mudstate.version);
    char *buff = alloc_mbuf("do_version");
    sprintf(buff, "Build date: %s", MUX_BUILD_DATE);
    notify(executor, buff);
    free_mbuf(buff);
}

void NDECL(init_version)
{
#ifdef WIN32
#ifdef BETA
        sprintf( mudstate.version, "MUX %s for Win32 #%s [BETA]",
            MUX_VERSION, MUX_BUILD_NUM);
        sprintf( mudstate.short_ver, "MUX %s Beta Win32", MUX_VERSION);
#else // BETA
        sprintf( mudstate.version, "MUX %s for Win32 #%s [%s]",
            MUX_VERSION, MUX_BUILD_NUM, MUX_RELEASE_DATE);
        sprintf( mudstate.short_ver, "MUX %s Win32", MUX_VERSION);
#endif // BETA
#else // WIN32
#ifdef BETA
        sprintf( mudstate.version, "MUX %s #%s [BETA]", MUX_VERSION,
            MUX_BUILD_NUM);
        sprintf( mudstate.short_ver, "MUX %s Beta", MUX_VERSION);
#else // BETA
        sprintf( mudstate.version, "MUX %s #%s [%s]", MUX_VERSION,
            MUX_BUILD_NUM, MUX_RELEASE_DATE);
        sprintf( mudstate.short_ver, "MUX %s", MUX_VERSION);
#endif // BETA
#endif // WIN32

    STARTLOG(LOG_ALWAYS, "INI", "START");
    log_text("Starting: ");
    log_text(mudstate.version);
    ENDLOG;
    STARTLOG(LOG_ALWAYS, "INI", "START");
    log_text("Build date: ");
    log_text(MUX_BUILD_DATE);
    ENDLOG;
}

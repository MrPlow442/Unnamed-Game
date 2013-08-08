#ifndef DBGMSG_H
#define DBGMSG_H

#ifdef _DEBUG
#include <iostream>
#	define DBGMSG(msg) std::cerr << "DBG: " << __FILE__ << "(" << __LINE__ << ") " << msg << std::endl
#	define DBGMSGR(msg) std::cerr << "DBG: " << msg << std::endl;
#else
#	define DBGMSG(msg) do {} while (0)
#	define DBGMSGR(msg) DBGMSG(msg)
#endif


#endif // DBGMSG_H

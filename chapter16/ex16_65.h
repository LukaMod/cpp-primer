#ifndef DEBUG_REP_H_
#define DEBUG_REP_H_

#include <string>
#include <sstream>

template <typename T>
std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

std::string debug_rep(const std::string&);

template<>
std::string debug_rep(char *p);

template<>
std::string debug_rep(const char *p);

#endif // !DEBUG_REP_H_

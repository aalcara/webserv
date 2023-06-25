#include "webserv.hpp"

std::string ltrim(const std::string &s, std::string remove)
{
	size_t start = s.find_first_not_of(remove);
	if (start == std::string::npos)
		return "";
	return (s.substr(start));
}

std::string rtrim(const std::string &s, std::string remove)
{
	size_t end = s.find_last_not_of(remove);
	if (end == std::string::npos)
		return "";
	return (s.substr(0, end + 1));
}

std::string trim(const std::string &s, std::string remove)
{
	return rtrim(ltrim(s, remove), remove);
}
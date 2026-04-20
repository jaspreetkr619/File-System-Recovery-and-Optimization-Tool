#ifndef CACHE_H
#define CACHE_H

#include <string>

void putCache(std::string key, std::string value);
std::string getCache(std::string key);
void showCache();

#endif
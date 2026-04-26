#ifndef CACHE_H
#define CACHE_H

#include <string>
using namespace std;

void putCache(string key, string value);
string getFromCache(string key);
void showCache();

#endif
#ifndef GXP_H
#define GXP_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void step();
void create(ifstream &);
bool rend();
bool count();
void calc(int, int);
void calc(int *);
void view(int, int);
void view();
int *m, *n;
bool **mass;
#endif // GXP_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct SkewHeap{
	SkewHeap* lson;
	SkewHeap* rson;
	int w;
};

SkewHeap *root;
#include "testlib.h"

int main(){
	registerValidation();
	int Ai,Bi,Ci;
	Ai=inf.readInt(15,300,"Ai");
	inf.readSpace();
	Bi=inf.readInt(15,300,"Bi");
	inf.readSpace();
	Ci=inf.readInt(15,300,"Ci");
	inf.readEoln();
	int Va,Vb;
	Va=inf.readInt(1,2147483647,"Va");
	inf.readSpace();
	Vb=inf.readInt(1,2147483647,"Vb");
	inf.readEoln();
	inf.readEof();
	return 0;
}
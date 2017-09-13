#include "lua_adapter.hpp"
#include <iostream>

using namespace std;

int main () {  	

	LuaAdapter lua("main.lua");
	string s;
	lua.get("t.szoveg",s);
	cout << s << endl;

	lua.openTable("t");
		string a;
		lua.getField("alma",a);
		cout << a << endl;
		int e;
		lua.getField("egy",e);
		cout << e << endl;
		lua.openNestedTable("g");
			double x,y;
			lua.getField("x",x);
			lua.getField("y",y);
			cout << x << " " << y << endl;
			lua.openNestedTable("h");
				lua.getField(1,s);
				cout << s << endl;
				lua.getField(2,s);
				cout << s << endl;
			lua.closeTable();
		lua.closeTable();
	lua.closeTable();

	lua.callFunction("luafuggveny",string("alma"),s);
	cout << s << endl;



	while(cin);
	return 0;
	
}
#include <iostream>

using namespace std;

class B1
{

public:
	virtual void vf(){

		cout<<"B1::vf()\n";
	}

	virtual void pvf()=0;


	void f()
	{
		cout<<"B1::f()\n";
	}


};






class D1 : public B1
{
public:
	void vf() override
	{
		cout<<"D1::vf()\n";
	}


	

	void f()
	{
		cout<<"D1::f()\n";
	}


};




class D2 : public D1
{
	void pvf() override
	{
		cout<<"D2::pvf()\n";
	}

};




class B2
{
public:
	virtual void pvf()=0;


};



class D21 : public B2
{

string s="this is a string from D21";

public:

	void pvf()override
	{
		cout<<s<<endl;
	}
	

};

class D22 : public B2
{
	int memb = 69;

	void pvf()override
	{
		cout<<memb<<endl;
	}
};


void f(B2 &b)
{
	b.pvf();
}



void call(B1& b)
{
	b.vf();
	b.f();
	b.pvf();
}





int main()
{

//B1 b;   nem lehetséges, mert absztrakt osztály
//D1 d;
//B1 &referencia{d};

D2 d;

call(d);


D21 d21;

D22 d22;

f(d21);
f(d22);


}
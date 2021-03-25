#include <iostream>
#include <string>
#include <vector>

using namespace std;


void error(string s){

	throw runtime_error(s);
}



struct Person
{


private: 

	std::string first_name;
	std::string last_name;
	int age;



	int name_check(std::string f,std::string l){
		std::vector<char> special={';',':','"','\'','[',']','*','&','^','%','$','#','@','!'};
		for(auto c : special)
		{
			if(f.find(c)!= std::string::npos)return 1;
			if(l.find(c)!= std::string::npos)return 1;
		}

		return 0;


	}

public:
 
	Person():first_name(""),last_name(""),age(0){};
	Person(std::string fname,std::string lname, int a){
		if(a<0 || a>150)error("hibás életkor! Person()");
		if(name_check(fname,lname))error("név nem tartalmazhat speciális karaktert! Person()" );

		first_name=fname;
		last_name=lname;
		age=a;
	}


	int get_age()const{
		return age;
	}

	std::string name()const{
		return first_name +" "+ last_name;
	}
};



std::ostream& operator<<(std::ostream& os, const Person& p){

return os<<p.name()<<" "<<p.get_age()<<"\n";
}


std::istream& operator>>(std::istream& is, Person& p){
	std::string tempf;
	std::string templ;
	int tempa;

	is>>tempf>>templ>>tempa;
	p=Person(tempf,templ,tempa);

	return is;
}



int main(){


	Person p;

	std::cin>>p;

	std::cout<<p;



}
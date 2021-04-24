#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Record
{
	std::string name;
	std::string address;
};


struct Compare_by_name
{
	bool operator()(const Record& a, const Record& b) const
		{return a.name < b.name;}
};


int main(){


	std::vector<Record> vr;

	for(std::string a,b; std::cin>>a>>b && (a!="q" || b!="q"); )
	{
		Record first;
		first.name=a;
		first.address=b;

		vr.push_back(first);

	}

	std::cout<<"before sort: \n";

	for(const auto& record : vr)
		std::cout<<record.name<<' '<<record.address<<"\n";



	std::sort(vr.begin(),vr.end(),Compare_by_name());


	std::cout<<"aftersort: \n";

	for(const auto& record : vr)
		std::cout<<record.name<<' '<<record.address<<"\n";

}
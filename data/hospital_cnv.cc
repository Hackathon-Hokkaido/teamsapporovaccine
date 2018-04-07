#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

bool includes_maru( const std::string& str ) {
	return str.find( "○" ) != std::string::npos;
}

std::string toVaccineNumbers( const std::vector<std::string>& elms ) {
	std::vector<std::string> vaccs;
	for( size_t i = 7; i < 19; ++i ) {
		if( includes_maru( elms[i]) )  vaccs.push_back( std::to_string(i - 6) );
	}
	return boost::algorithm::join( vaccs, ":" );
}

std::string splitAddress( std::string& address ) {
	std::string result;
	size_t n = address.find_first_of(" ");
	if( n != std::string::npos ) {
		result = address.substr( 0, n );
		address = address.substr( n );
	} else {
		result = address;
		address = "";
	}
	return result;
}

int main() {
  std::string line;
	std::ifstream ifs;
	ifs.open( "hospitals.csv");
	while( ifs.good() ) {
	  std::vector<std::string> elms; 
		std::getline( ifs, line );
		boost::split( elms, line, boost::is_any_of(","));
		std::string address = elms[2] + elms[3] + elms[4];
		std::string new_address = splitAddress( address );
		std::cout << elms[0] << "," << elms[1] << "," << new_address << "," << address << "," << elms[5] << "-" << elms[6] << "," << toVaccineNumbers( elms ) << std::endl;
	}
	return 0;
}
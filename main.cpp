#include "infmem.hpp"
#include <iostream>
int main(){
	RoundMem<int,3> mytree(0);
	mytree[9] = 74890172;
    mytree[7] = 72;
		for(size_t j = 0; j < mytree.size(); j++)
			if(mytree[j] != 0)
				std::cout << "Value is " << mytree[j] << std::endl;
}

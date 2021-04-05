#include "infmem.hpp"
#include <iostream>
int main(){
	InfVec<RoundMem<int,3>> mytree;
	mytree[12][9] = 74890172;
    mytree[13][7] = 72;
	for(size_t i = 0; i < mytree.size(); i++)
		for(size_t j = 0; j < mytree[i].size(); j++)
			if(mytree[i][j] != 0)
				std::cout << "Value is " << mytree[i][j] << std::endl;
}

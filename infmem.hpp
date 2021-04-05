#include <cstdint>
#include <vector>
#include <array>
//Infinite memory container
//operator[] guarantees that the memory location exists.
//resize forces a certain size.

template <typename T, size_t pow2size>
class RoundMem{
	public:
		RoundMem() = default;
		RoundMem(T a) {
			for(size_t i = 0; i < size(); i++)(*this)[i] = a;
		}
		RoundMem(const RoundMem& other){data = other.data;}
		size_t size(){return ((size_t)1<<(pow2size-1));}
		T& operator[](size_t index){
			return data[index & (((size_t)1<<(pow2size-1)) - 1)];
		}
	private:
		std::array<T, (size_t)1<<(pow2size-1)> data;
};

template <typename T>
class InfVec{
	public:
		InfVec(){vec = std::vector<T>();}
		InfVec(size_t n){vec = std::vector<T>(n);}
		InfVec(const InfVec& other){vec = other.getvec();}
		T& operator[](size_t index){
			if(index >= vec.size()) vec.resize(index+1);
			return vec[index];
		}
		size_t size(){return vec.size();}
		void resize(size_t n){vec.resize(n);}
		void resize(size_t n, T val){vec.resize(n, val);}
		std::vector<T> getvec() const {return vec;}
	private:
		std::vector<T> vec;
};

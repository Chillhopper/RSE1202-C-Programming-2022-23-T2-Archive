#ifndef CONT_H
#define CONT_H
#include<cstddef>
namespace hlp2 {
	class cont
	{
	public:
		// Other declarations

		virtual size_t size() const = 0;
		virtual void clear(){};
		//virtual bool is_empty() const = 0;
		
		bool is_empty(){
			bool r = size()==0?true:false;
			return r;
		}
		
	};
}

#endif

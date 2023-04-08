#ifndef CONT_H
#define CONT_H
#include<cstddef>
namespace hlp2 
{
	class cont
	{
    	public:
    		// Other declarations
    
            virtual ~cont() {}
    		virtual size_t size() const = 0;
    		virtual void clear() = 0;
    
    
        virtual bool is_empty() const
        {
            return size() == 0;
        }
    		
	};
}

#endif

#ifndef __TINYSTL_CONSTRUCT_HPP
#define __TINYSTL_CONSTRUCT_HPP

#include <new>
#include "Type_traitsTiny.hpp"
#include "IteratorTiny.hpp"

namespace TinySTL
{

template<typename T,typename V>
inline void construct(T* p,const V& value)
{
	new (p) V(value);
}

template<typename T>
inline void destroy(T* p)
{
	p->~T();
}

template<typename Iterator>
inline void __destroy_aux(Iterator first,Iterator last,__true_type)
{
	for(;first!=last;++first)
	{
		destroy(&*first);
	}
}
template<typename Iterator>
inline void __destroy_aux(Iterator first,Iterator last,__false_type)
{

}

template<typename Iterator,typename T>
inline void __destroy(Iterator first,Iterator last,T*)
{
	typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
	__destroy_aux(first,last,trivial_destructor());
}


template<typename Iterator>
inline void destroy(Iterator first,Iterator last)
{
	__destroy(first,last,value_type(first));

}




}





#endif
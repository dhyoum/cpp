/ primary template : 아무것도 없는 경우만 만족
template<typename... Ts>
struct xtuple {
    static constexpr int N = 0;
};

// parital specialization
template<typename T, typename... Ts>
struct xtuple<T, Ts...> : xtuple<Ts...> {   // 어떻게 여기다 이렇게??
    using BaseType = xtuple<Ts...>;
    
    T value;

    xtuple() = default;
    xtuple(const T& v, 
        const Ts&... args) : value(v), BaseType(args...) {}
    static constexpr int N = BaseType::N+1;
};

template<int N, typename T>
struct xtuple_element_type {
	typedef T type;
};
template<typename T, typename ... Types>
struct xtuple_element_type<0, xtuple<T, Types...>> {
	typedef T type; 
	typedef xtuple<T, Types...> tupleType; 
};

template<int N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>> {
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::type      type;
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::tupleType tupleType;
};

//--------------------------------------------------------------
template<typename T> void foo(T& tp)
{
	typename xtuple_element_type<2, T>::type n;      // 1번째 요소 타입
	typename xtuple_element_type<2, T>::tupleType t; // 1번째 요소를 저장하는 부모타입

	cout << typeid(n).name() << endl;
	cout << typeid(t).name() << endl;
}

template<int N, typename T> 
typename xtuple_element_type<N, T>::type&   xget(T& tp)
{
//	return ((typename xtuple_element_type<N, T>::tupleType&)tp).value;

	return (static_cast<typename xtuple_element_type<N, T>::tupleType&>(tp)).value;
}

int main()
{
    xtuple<> t0;
    xtuple<short> t1(1);
    xtuple<double, short> t2(2.3, 1);
    xtuple<int, double, short> t3(3, 3.4, 2);
}

/ primary template : 아무것도 없는 경우만 만족
template<typename... Ts>
struct xtuple {
    static constexpr int N = 0;
};

// parital specialization
template<typename T, typename... Ts>
struct xtuple<T, Ts...> : xtuple<Ts...> {
    using BaseType = xtuple<Ts...>;
    
    T value;

    xtuple() = default;
    xtuple(const T& v, 
        const Ts&... args) : value(v), BaseType(args...) {}
    static constexpr int N = BaseType::N+1;
};

int main()
{
    xtuple<> t0;
    xtuple<short> t1(1);
    xtuple<double, short> t2(2.3, 1);
    xtuple<int, double, short> t3(3, 3.4, 2);
}

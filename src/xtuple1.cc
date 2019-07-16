// primary template : 아무것도 없는 경우만 만족
template<typename... Ts>
struct xtuple {
    static constexpr int N = 0;
};

// parital specialization
template<typename T, typename... Ts>
struct xtuple<T, Ts...> {
    T value;

    xtuple() = default;
    xtuple(const T& v) : value(v) {}
    static constexpr int N = 1;
};

int main() {
    // 문제점 제일 처음 원소만 저장한다.
    xtuple<short> t1(1);
    xtuple<double, short> t2(2.3);
    xtuple<int, double, short> t3(3);
}

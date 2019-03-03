### memory_order_relaxted 
원자성 작업과 관련하여 전적으로 컴파일러와 하드웨어에 의존하며 별도 작업 순서에 관여하지 않는다.

### memory_order_acquire
읽기 작업과 쓰기 작업에 충돌이 발생한다면 읽기 작업 이전에 먼저 쓰기 작업을 수행함을 의미한다.
- load() 함수에서만 사용이 가능함

### memory_order_release
읽기 작업과 쓰기 작업에 충돌이 발생한다면 읽기 작업 이전에 먼저 쓰기 작업을 수행함을 의미한다.
- store() 함수에서만 사용이 가능함

### memory_order_consume
memory_order_acquire 과 유사한 작업을 수행한다. 다만 아래 상수를 사용하는 작업도 허용함을 뜻한다.

### memory_order_seq_cst
단계별 연속작업( sequentially consistent) 또는 다른 말로 RMW (Read-Modify-Write)의 단일 작업을 수행한다.


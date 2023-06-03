# CPP_Module02

New rules

Orthodox Canonical Form.
- 기본 생성자
- 복사 생성자
- 복사 할당 생성자
- 소멸자
네 개의 멤버 변수를 구현해야 한다.

## Exercise 00: My First Class in Orthodx Canonical Form

정수와 부동 소수점을 잘 알고 있다고 생각하면 오산이다.
3개의 글을 읽고 오라. 

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

지금까지의 코드에서 사용하는 모든 숫자는 기본적으로 int, float 또는 그 변형 중 하나였다.
위의 글을 읽고 나면 int와 float는 서로 반대되는 특성을 가지고 있다고 가정해도 무방할 것이다.
또한 새로운 숫자 유형인 고정 소수점을 알게될 것이다!
대부분의 언어에서 사용되는 단일 정보 저장 유형에서 사라진 고정 소수점은 성능, 정확도, 범위, 정밀도 사이에서 균형을 이루고 있다.
고정 소수점은 컴퓨터 그래픽, 사운드 처리, 과학 프로그래밍 등에서 사용된다.

C++은 고정 소수점 숫자가 없다. 따라서 이를 추가할 것이다.
이 기사를 읽고 시작하는 것이 좋을 것이다.
https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html

고정 소수점 수를 표현하는 Orthodox Canonical Form 을 생성하라.
- private
    - 고정 소수점의 수를 저장할 integer
    - 분수비트를 저장할 static const int: 이 값은 정수 8이다.
- public
    - 기본 생성자: 고정 소수점의 수를 0으로 초기화
    - 복사 생성자
    - 할당 연산 오버로딩
    - 소멸자
    - int getRawBits( void ) const; 고정 소수점의 원형 데이터를 반환한다.
    - void  setRawBits( void ); 고정 소수점의 원형 데이터를 설정한다.
```
#include <iostream>
int main( void ) 
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
```
- 결과
```
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destruct
```
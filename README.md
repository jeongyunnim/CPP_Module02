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

## Exercise 01: Towards a more useful fixed-point number class

이전 예제에서는 좋은 시작이었으나, 만든 클래스는 쓸모가 없었다. 0.0만 표현할 수 있을뿐이었다.

아래의 생성자와 멤버함수를 클래스에 추가헤야 한다.

- const int를 파라미터로 받는 생성자.
    고정 소수점 수와 일치하는 값으로 변환한다. 분모 비트의 값은 8로 초기화 된다.

- const float를 파라미터로 받는 생성자.
    고정 소수점 수와 일치하는 값으로 변환한다. 분모 비트의 값은 8로 초기화 된다.

- float toFloat(void) const;
    고정 소수점에서 부동 소수점 수로 변환한다.

- int toInt(void) const;
    고정 소수점에서 정수로 변환한다.

또한 아래의 함수를 Fixed class에 추가해야 한다.

- 연산자 << 오버로딩
    float 으로 표현된 고정 소수점 수를 output stream에 매개변수로 전달한다.

```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
```
출력은 이와 같아야 한다.
```
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

## Exercise 02: Now we're talking

public 멤버 함수로 아래의 연산자들을 오버로드하라.
- 비교 연산자: >, <, >=, <=, ==, !=
- 산술 연산자: +. -, *, /
- 증감연산자 ++, -- (전위 연산자와 후위연산자): 고정 소수점에서 표현할 수 있는 가장 작은 단위를 증감시킨다.

public 멤버 함수로 아래의 함수를 오버로드하라.
- Fixed	Fixed::max(const Fixed& lhs, const Fixed& rhs)
- Fixed	Fixed::max(Fixed& lhs, Fixed& rhs)
- Fixed	Fixed::min(const Fixed& lhs, const Fixed& rhs)
- Fixed	Fixed::min(Fixed& lhs, Fixed& rhs)

클래스를 테스트하는 코드를 만들어보아라.
아래의 코드를 실행한 뒤 결과를 비교해보아라.

```
#include <iostream>

int main( void ) {

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
```

실행 결과
```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

## Exercise 03: BSP

이제 우리는 고정소수점의 클래스를 갖게 됐다. 사용해볼까나?
임의의 점이 삼각형 안에 있는지를 판단하는 함수를 구현하라.

(BSP는 binary space partitioning의 약자이다.)

- Orthodox Canonical Form에 따라 2차원 점을 표현하는 Point 클래스를 만들어라.
- private
    - Fixed const x;
    - Fixed const y;
    - Anything else useful;
- public
    - x와 y가 0으로 초기화 되는 기본 생성자.
    - 두 개의 const float을 파라미터로 받는 생성자. (const float x, const float y)
    - 복사 생성자
    - 대입 연산자 오버로딩
    - 소멸자
    - Anything else useful;

- 결론적으로 아래의 bsp함수를 구현하여야 한다.
    `bool bsp( Point const a, Point const b, Point const point)`
    - a, b, c: 삼각형의 꼭짓점
    - point: 체크할 2차원 점
    - 반환 값: 삼각형 안에 있다면 `true`, 밖에 있다면 `false`. 따라서, 포인트가 꼭짓점 또는 모서리에 존재하면 `false`를 반환한다.

테스트 코드를 직접 작성하여 테스트 해보아라.

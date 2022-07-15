// Vector_Property_Function.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include<DirectXMath.h>
#include<DirectXPackedVector.h>

std::ostream& XM_CALLCONV operator<<(std::ostream& os, DirectX::FXMVECTOR v)
{
	DirectX::XMFLOAT3 dest;
	DirectX::XMStoreFloat3(&dest, v);
	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main()
{
	std::cout.setf(std::ios_base::boolalpha);

	if (!DirectX::XMVerifyCPUSupport)
	{
		std::cout << "DirectX math를 지원하지 않음" << std::endl;
		return 0;
	}

	DirectX::XMVECTOR p = DirectX::XMVectorZero();
	DirectX::XMVECTOR q = DirectX::XMVectorSplatOne();
	DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	DirectX::XMVECTOR v = DirectX::XMVectorReplicate(-2.0f);
	DirectX::XMVECTOR w = DirectX::XMVectorSplatZ(u);
	
	std::cout << "p= " << p << std::endl;
	std::cout << "q= " << q << std::endl;
	std::cout << "u= " << u << std::endl;
	std::cout << "v= " << v << std::endl;
	std::cout << "w= " << w << std::endl;

	return 0;
}


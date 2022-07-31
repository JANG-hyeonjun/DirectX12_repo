// DirectX12Math_Matrix_Example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Windows.h>
#include <iostream>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

using namespace DirectX;
 
std::ostream& XM_CALLCONV operator<<(std::ostream& os, DirectX::FXMVECTOR v)
{
	DirectX::XMFLOAT4 dest;
	DirectX::XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";	
	return os;
}

std::ostream& XM_CALLCONV operator<<(std::ostream& os, DirectX::FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << DirectX::XMVectorGetX(m.r[i]) << "\t";
		os << DirectX::XMVectorGetY(m.r[i]) << "\t";
		os << DirectX::XMVectorGetZ(m.r[i]) << "\t";
		os << DirectX::XMVectorGetW(m.r[i]) << std::endl;
	}
	return os;
}

int main()
{
	if (!DirectX::XMVerifyCPUSupport())
	{
		std::cout << "DirectX Math를 지원하지 않음" << std::endl;
		return 0;
	}
	
	DirectX::XMMATRIX A(1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, 2.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 4.0f, 0.0f,
						1.0f, 2.0f, 3.0f, 1.0f);

	DirectX::XMMATRIX B = DirectX::XMMatrixIdentity();

	DirectX::XMMATRIX C = A * B;

	DirectX::XMMATRIX D = DirectX::XMMatrixTranspose(A);

	DirectX::XMVECTOR det = DirectX::XMMatrixDeterminant(A);
	DirectX::XMMATRIX E = DirectX::XMMatrixInverse(&det, A);

	DirectX::XMMATRIX F = A * E;

	std::cout << "A = " << std::endl << A << std::endl;
	std::cout << "B = " << std::endl << B << std::endl;
	std::cout << "C =  A * b = " << std::endl << C << std::endl;
	std::cout << "D = tranpose(A) = " << std::endl << D << std::endl;
	std::cout << "det = determinatnt(A) = " << det << std::endl << std::endl;
	std::cout << "E = Inverse(A) = " << std::endl << E << std::endl;
	std::cout << "F = A * E = " << std::endl << F << std::endl;

	return 0;
}


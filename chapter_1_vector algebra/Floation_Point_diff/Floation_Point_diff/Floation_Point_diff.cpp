// Floation_Point_diff.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

//두 부동소주점 근사적 상등 확인 함수
const float Epsilon = 0.001f;
bool Equals(float lhs, float rhs)
{
	//lhs와 rhs사이의 거리가 Epsilon보다 작은가? 
	return std::fabs(lhs - rhs) < Epsilon ? true : false;
}

int main()
{
	std::cout.precision(8);

	if (!DirectX::XMVerifyCPUSupport)
	{
		std::cout << "DirectMath를 지원하지 않음" << std::endl;
		return 0;
	}

	DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	DirectX::XMVECTOR n = DirectX::XMVector3Normalize(u);

	DirectX::XMFLOAT3 conFirmVec;
	DirectX::XMStoreFloat3(&conFirmVec, n);

	//std::cout << conFirmVec.x << ", " << conFirmVec.y << ", " << conFirmVec.z << std::endl;
	
	float LU = DirectX::XMVectorGetX(DirectX::XMVector3Length(n));

	//수학적으로 정규화한 벡터는 길이가 1이여야 한다.
	std::cout << LU << std::endl;

	if (LU == 1.0f)
		std::cout << "길이 1" << std::endl;
	else
		std::cout << "길이 1 아님 " << std::endl;


	if (Equals(LU, 1.0f))
		std::cout << "근사적 일치" << std::endl;
	else
		std::cout << "근사적 불일치 " << std::endl;

	//1을 임의의 지수로 아무리 곱해도 1하지만 오차가 누적되면서 오히려 1과 더 멀어지게된다.
	float powLU = std::powf(LU, 1.0e6f);
	std::cout << "LU^(10^6) = " << powLU << std::endl;
	
	//그래서 부동 소주점의 부정확함때문에 두 부동소수점의 상등을 판단할때는 두수가 근사적으로 같은지를 봐야한다.
	//이를 위해 Epsilon이란 상수로 코드안에 정리해둔다.  
	//두수가 같은지를 판정할때는 두 수의 거리(차이 절댓값)가 그 Epsilon보다 작은지를 본다/.

	//DirectXMath라이브러리 에는 두벡터 의 상등을 판정하는 XMVector3NearEqaul이란 함수가 존재 
	//Epsilon은 앞에서 말한 허용오차

	/* document 참고
	* bool XM_CALLCONV XMVector3NearEqual(
	[in] FXMVECTOR V1,
	[in] FXMVECTOR V2,
	[in] FXMVECTOR Epsilon
	) noexcept;
	
	return ( ( abs( V1.x - V2.x ) <= Epsilon ) &&
		 ( abs( V1.y - V2.y ) <= Epsilon ) &&
		 ( abs( V1.z - V2.z ) <= Epsilon ));
	*/
	
	return 0;
}


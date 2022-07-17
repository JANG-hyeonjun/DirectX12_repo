// Vector_Propery2Function.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Windows.h>
#include <iostream>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

using namespace DirectX;

std::ostream& XM_CALLCONV operator<<(std::ostream& os, DirectX::FXMVECTOR v)
{
	DirectX::XMFLOAT3* dest = new DirectX::XMFLOAT3;
	DirectX::XMStoreFloat3(dest, v);
	os << "(" << dest->x << ", " << dest->y << ", " << dest->z << ")";
	return os;
}

int main()
{
	std::cout.setf(std::ios_base::boolalpha);

	if (!DirectX::XMVerifyCPUSupport)
	{
		std::cout << "DirectMath를 지원하지 않음" << std::endl;
		return 0;
	}

	DirectX::XMVECTOR n = DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	DirectX::XMVECTOR v = DirectX::XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	DirectX::XMVECTOR w = DirectX::XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	// XMVECTOR operator
	DirectX::XMVECTOR a = u + v;
	DirectX::XMVECTOR b = u - v;
	DirectX::XMVECTOR c = 10.0f * u;
	
	//길이
	DirectX::XMVECTOR L = DirectX::XMVector3Length(u);
	
	//정규화
	DirectX::XMVECTOR d = DirectX::XMVector3Normalize(u);

	//벡터 내적
	DirectX::XMVECTOR s = DirectX::XMVector3Dot(u, v);

	//벡터 외적
	DirectX::XMVECTOR e = DirectX::XMVector3Cross(u, v);

	DirectX::XMVECTOR projW,perpW;
	DirectX::XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	//X축에 대해 성분을 분해한 벡터들은 분명 수직을 이루고 있을 것이며 더하면 W일것이다,
	bool equal = DirectX::XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = DirectX::XMVector3NotEqual(projW + perpW, w) != 0;

	DirectX::XMVECTOR angleVec = DirectX::XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = DirectX::XMVectorGetX(angleVec);
	//수학적인 결과가 스칼라 값인경우에도 모든성분에 복사가 되서 XMVECTOR로 리턴받음을 기억할 것
	float angleDegrees = DirectX::XMConvertToDegrees(angleRadians);
	
	std::cout <<"u					  = "<< u <<std::endl;
	std::cout <<"v					  = "<< v <<std::endl;
	std::cout <<"w					  = "<< w <<std::endl;
	std::cout <<"n					  = "<< n <<std::endl;
	std::cout <<"a = u + v			  = "<< a << std::endl;
	std::cout <<"b = u - v			  = "<< b <<std::endl;
	std::cout <<"c = 10 * v			  = "<< c <<std::endl;
	std::cout <<"d = u / ||u||		  = "<< d <<std::endl;
	std::cout <<"e = u x v			  = "<< e <<std::endl;
	std::cout <<"L = ||u||			  = "<< L <<std::endl;
	std::cout <<"s =  u . v	          = "<< s <<std::endl;
	std::cout <<"projw				  = "<< projW  <<std::endl;
	std::cout <<"perpw				  = "<< perpW  <<std::endl;
	std::cout <<"projw + perpw  == w  = "<< equal <<std::endl;
	std::cout <<"projw + perpw  != w  = " << notEqual << std::endl;
	std::cout <<"angle				  = "<< angleDegrees <<std::endl;

	//DirectXMath는 계산이 덜 정확하지만 더 빠른 추정(estimation)함수들도 제공
	//속도를 위해 정확성을 조금 희생할 수 있는 상황이라면 이런 추정함수들을 사용할것
	//XMVECTOR XM_CALLCONV XMVector3LengthEst(FMXVECTOR V); 추정된 벡터 크기
	//XMVECTOR XM_CALLCONV XMVector3NormalizeEst(FXMVECTOR V) 추정된 단위 벡터를 돌려줌

	return 0;
}


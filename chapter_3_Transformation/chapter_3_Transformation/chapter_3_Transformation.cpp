#include <Windows.h>
#include <iostream>
#include <string>
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

void PrintVector(DirectX::FXMVECTOR v)
{
	std::cout << "결과: " << std::endl << v << std::endl;
}

void PrintMatrix(const std::string& matName, DirectX::FXMMATRIX pMat)
{
	std::cout << matName << std::endl << pMat << std::endl;
}

int main()
{
	if (!DirectX::XMVerifyCPUSupport())
	{
		std::cout << "DirectX Math를 지원하지 않음" << std::endl;
		return 0;
	}

	/*
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
	*/
	
	std::cout << "check Coordinate Transformation" << std::endl;
	DirectX::XMMATRIX scaleMatrix = DirectX::XMMatrixScaling(2.0, 2.0, 2.0);
	std::cout << "Scale Matrix: " << std::endl << scaleMatrix << std::endl;

	
	DirectX::XMVECTORF32 scaleElementVector{2.0,2.0,2.0,2.0};
	DirectX::XMMATRIX scaleMatrixFromVector = DirectX::XMMatrixScalingFromVector(scaleElementVector);
	std::cout << "Scale MatrixFromVector: " << std::endl << scaleMatrixFromVector << std::endl;

	DirectX::XMMATRIX rotationMatrixCriterionX = DirectX::XMMatrixRotationX(45.0);
	std::cout << "rotationMatrixCriterionX  " << std::endl << rotationMatrixCriterionX << std::endl;

	DirectX::XMMATRIX rotationMatrixCriterionY = DirectX::XMMatrixRotationY(45.0);
	std::cout << "rotationMatrixCriterionY  " << std::endl << rotationMatrixCriterionY << std::endl;

	DirectX::XMMATRIX rotationMatrixCriterionZ = DirectX::XMMatrixRotationZ(45.0);
	std::cout << "rotationMatrixCriterionZ  " << std::endl << rotationMatrixCriterionZ << std::endl;

	DirectX::XMVECTORF32 zAxisVector{0.0,0.0,1.0};
	DirectX::XMMATRIX arbitraryAxisRotationMatrix = DirectX::XMMatrixRotationAxis(zAxisVector, 45.0);
	std::cout << "arbitraryAxisRotationMatrix " << std::endl << arbitraryAxisRotationMatrix << std::endl;
	
	DirectX:; XMMATRIX translationMatrix = DirectX::XMMatrixTranslation(1.0, 1.0, 1.0);
	std::cout << "translationMatrix " << std::endl << translationMatrix << std::endl;

	DirectX::XMVECTORF32 translationVector{ 2.0,3.0,4.0 };
	DirectX::XMMATRIX translationMatFromVec = DirectX::XMMatrixTranslationFromVector(translationVector);
	PrintMatrix("translationMatFromVec", translationMatFromVec);


	//Operation dot & Vector - dot
	DirectX::XMVECTORF32 resultTranslationVector{1.0, 1.0, 1.0};
	DirectX::XMVECTOR resultTranslationVector2 = DirectX::XMVectorSet(1.0, 1.0, 1.0, 0.0);
	PrintVector(DirectX::XMVector3TransformCoord(resultTranslationVector, translationMatFromVec));

	PrintVector(DirectX::XMVector3Transform(resultTranslationVector2, translationMatFromVec));

	return 0;
}
#include "pch.h"
#include "Mesh.h"
#include "Engine.h"

void Mesh::Init(vector<Vertex>& vec)
{
	_vertexCount = static_cast<uint32>(vec.size());
	uint32 bufferSize = _vertexCount * sizeof(Vertex);

	//D3D12_HEAP_TYPE_UPLOAD 데이터를 복사하는데에만 써야하는데 데이터를 전달하거나 GPU에서 해당버퍼를 참고해서
	//계속활용하는 용도로도 사용 -> 그러니까 지금은 공용으로 사용하는 느낌
	//원래는 Default와 Upload를 만들어서 사용
	D3D12_HEAP_PROPERTIES heapProperty = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	D3D12_RESOURCE_DESC desc = CD3DX12_RESOURCE_DESC::Buffer(bufferSize);

	DEVICE->CreateCommittedResource(
		&heapProperty,
		D3D12_HEAP_FLAG_NONE,
		&desc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&_vertexBuffer)); //-> GPU안에있는 공간을 가리킴 
	//GPU 쪽에 가서 어떤 공간을 할당하고 거기서 필요한 정보를 넣어줄테니 공간을 확보해줘

	//결과적으로 버퍼를 만들어서 거기다가 데이터를 전달하고 GPU에서도 그 버퍼를 참고해서 사용하라고 2가지일을 준건데
	//MSDN에선 Default 타입으로 만들어주고 데이터를 전송할때만 업로드를 하나더 만들어라 라는 권고임

	// Copy the triangle data to the vertex buffer.
	void* vertexDataBuffer = nullptr;
	CD3DX12_RANGE readRange(0, 0); // We do not intend to read from this resource on the CPU.
	_vertexBuffer->Map(0, &readRange, &vertexDataBuffer);
	::memcpy(vertexDataBuffer, &vec[0], bufferSize);
	_vertexBuffer->Unmap(0, nullptr);
	//공간을 확보하고 GPU에 데이터전달(복사) 과정

	// Initialize the vertex buffer view.
	_vertexBufferView.BufferLocation = _vertexBuffer->GetGPUVirtualAddress();
	_vertexBufferView.StrideInBytes = sizeof(Vertex); // 정점 1개 크기
	_vertexBufferView.SizeInBytes = bufferSize; // 버퍼의 크기	
	//이제 View를 만든다. 각각 어디에 위치 크기가 얼마인지 CPU에선 GPU가 어떤지 알수가 없으니 
	//View라는것을 통해 묘사를 해서 볼수 있는것 그러면 GPU에서도 View를 통해 이해하게됨 

}

void Mesh::Render()
{
	/// <summary>
	// 실제로 View를 이용해 먼가를 건네줌
	/// </summary>
	CMD_LIST->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); //기본적으로 삼각형 형태로 연결이 되어 있다.
	CMD_LIST->IASetVertexBuffers(0, 1, &_vertexBufferView); // Slot: (0~15) //저 View를 사용해 데이터를 활용 할거다.
	CMD_LIST->DrawInstanced(_vertexCount, 1, 0, 0); //그려줘를 예약
}

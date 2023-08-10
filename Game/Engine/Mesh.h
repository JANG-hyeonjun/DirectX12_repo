#pragma once


//정점으로 이루어진 물체

class Mesh
{
public:
	void Init(vector<Vertex>& vec);
	void Render();

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {}; //리소스를 가리키고 지칭하고 설명하는 친구
	uint32 _vertexCount = 0;
};


#pragma once

// [계약서 / 결재]

// CPU [          ]		GPU [        ]
// 한국 [          ]		베트남 [        ]

//내가 어떠한 레지스터 그리고 어떠한 버퍼를 활용 하겠다. -> 어떤 정책을 그리고 어떤 땅을 사용하겠다는 계약서를 쓰는 느낌
class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }
private:
	//ComPtr 로 되어있는 대부분은 GPU한테 내가 요청을 하는거고 거기서 어떤 객체가 만들어지는것(내부에서 알아서)
	ComPtr<ID3D12RootSignature> _signature;
};


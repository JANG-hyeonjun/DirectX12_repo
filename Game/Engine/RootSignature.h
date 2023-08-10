#pragma once

// [��༭ / ����]

// CPU [          ]		GPU [        ]
// �ѱ� [          ]		��Ʈ�� [        ]

//���� ��� �������� �׸��� ��� ���۸� Ȱ�� �ϰڴ�. -> � ��å�� �׸��� � ���� ����ϰڴٴ� ��༭�� ���� ����
class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }
private:
	//ComPtr �� �Ǿ��ִ� ��κ��� GPU���� ���� ��û�� �ϴ°Ű� �ű⼭ � ��ü�� ��������°�(���ο��� �˾Ƽ�)
	ComPtr<ID3D12RootSignature> _signature;
};


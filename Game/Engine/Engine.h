#pragma once


class Engine
{
public:
	void Init(const WindowInfo& info);
	void Render();
public:
	void RenderBegin(); //CMD Q에 이런 저런 요청사항을 넣어준다. 
	void RenderEnd(); //쌓은 일감들을 GPU에 외주를 맡겨가지고 실질적으로 모든 일감들을 그리는 작업이 실행되는 부분 

	void ResizeWindow(int32 width, int32 height);

private:
	//그려질 화면크기랑 연관이 있다.
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	shared_ptr<class Device> _device;
	shared_ptr<class CommandQueue> _cmdQueue;
	shared_ptr<class SwapChain> _swapChain;
	shared_ptr<class DescriptorHeap> _descHeap;
};

